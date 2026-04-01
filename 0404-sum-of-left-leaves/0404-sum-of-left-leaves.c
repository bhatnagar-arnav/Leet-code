
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int dfs(struct TreeNode* node, int isLeft) {
    if (node == NULL) return 0;
    if (node->left == NULL && node->right == NULL) {
        return isLeft ? node->val : 0;
    }

    return dfs(node->left, 1) + dfs(node->right, 0);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL) return 0;
    return dfs(root, 0);
}