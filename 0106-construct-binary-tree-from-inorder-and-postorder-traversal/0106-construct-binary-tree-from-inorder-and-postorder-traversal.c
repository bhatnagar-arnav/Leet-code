struct TreeNode* build(int* inorder, int inStart, int inEnd, int* postorder, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postEnd];
    root->left = root->right = NULL;
    int inRoot = inStart;
    while (inRoot <= inEnd && inorder[inRoot] != root->val) inRoot++;
    int leftSize = inRoot - inStart;
    root->left = build(inorder, inStart, inRoot - 1, postorder, postStart, postStart + leftSize - 1);
    root->right = build(inorder, inRoot + 1, inEnd, postorder, postStart + leftSize, postEnd - 1);
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    return build(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}