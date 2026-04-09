
int cameras;

int dfs(struct TreeNode* root) {
    if (!root) return 1;
    int left = dfs(root->left);
    int right = dfs(root->right);
    if (left == 0 || right == 0) {
        cameras++;
        return 2;
    }
    if (left == 2 || right == 2) return 1;
    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (dfs(root) == 0) cameras++;
    return cameras;
}