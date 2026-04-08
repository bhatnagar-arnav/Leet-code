/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if (!root) return;
    flatten(root->left);
    flatten(root->right);
    if (root->left) {
        struct TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        struct TreeNode* curr = root->right;
        while (curr->right) curr = curr->right;
        curr->right = temp;
    }
}