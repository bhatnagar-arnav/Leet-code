int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    
    struct TreeNode* stack[100];
    int top = -1;
    
    if (root) stack[++top] = root;
    
    while (top >= 0) {
        struct TreeNode* node = stack[top--];
        result[(*returnSize)++] = node->val;
        
        if (node->right) stack[++top] = node->right;
        if (node->left)  stack[++top] = node->left;
    }
    
    return result;
}