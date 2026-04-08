/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct QueueNode {
    struct TreeNode* node;
    int level;
    struct QueueNode* next;
};

void enqueue(struct QueueNode** head, struct TreeNode* node, int level) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->level = level;
    newNode->next = NULL;
    if (!*head) {
        *head = newNode;
    } else {
        struct QueueNode* temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

struct TreeNode* dequeue(struct QueueNode** head, int* level) {
    if (!*head) return NULL;
    struct QueueNode* temp = *head;
    struct TreeNode* node = temp->node;
    *level = temp->level;
    *head = temp->next;
    free(temp);
    return node;
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) return NULL;
    int* result = (int*)malloc(1000 * sizeof(int));
    struct QueueNode* queue = NULL;
    enqueue(&queue, root, 0);
    int currentLevel = -1;
    while (queue) {
        int level;
        struct TreeNode* node = dequeue(&queue, &level);
        if (level > currentLevel) {
            result[*returnSize] = node->val;
            (*returnSize)++;
            currentLevel = level;
        } else {
            result[*returnSize - 1] = node->val;
        }
        if (node->left) enqueue(&queue, node->left, level + 1);
        if (node->right) enqueue(&queue, node->right, level + 1);
    }
    return result;
}