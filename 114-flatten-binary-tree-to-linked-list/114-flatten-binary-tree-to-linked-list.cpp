class Solution {
private:
    void morrisTraversal(TreeNode *root) {
        TreeNode *curr = root;
        while(curr) {
            if(curr->left) {
                TreeNode *pred = curr->left; // Find inorder predecessor of curr node
                while(pred->right) {
                pred = pred->right;
                }
                pred->right = curr->right; // Make a link from inorder predecessor to right subtree
                curr->right = curr->left; // Make the left part as the right part (required in question).
                curr->left = NULL; // Make left NULL.
            } 
            curr = curr->right;
        }
    }
public:
    void flatten(TreeNode* root) {
        // Morris Traversal O(1) extra space
        if(root == NULL) return;
        morrisTraversal(root);
    }
};