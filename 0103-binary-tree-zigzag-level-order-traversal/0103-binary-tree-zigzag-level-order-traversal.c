/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: The returned arrays must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int capacity = 10000; 
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    *returnSize = 0;

    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * capacity);
    int front = 0, back = 0;
    queue[back++] = root;

    int leftToRight = 1;

    while (front < back) {
        int levelSize = back - front;
        int* level = (int*)malloc(sizeof(int) * levelSize);

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            int index = leftToRight ? i : (levelSize - 1 - i);
            level[index] = node->val;

            if (node->left) queue[back++] = node->left;
            if (node->right) queue[back++] = node->right;
        }

        result[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;
        leftToRight = !leftToRight;
    }

    free(queue);
    return result;
}