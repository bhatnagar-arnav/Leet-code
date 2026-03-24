
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    void dfs(struct TreeNode* node) {
        if (node == NULL) return;
        dfs(node->left);                     
        result[(*returnSize)++] = node->val;  
        dfs(node->right);                     
    }

    dfs(root);
    return result;
}