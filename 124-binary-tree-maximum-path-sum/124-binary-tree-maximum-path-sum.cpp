/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int f(TreeNode* root,int& ans){
        if(root ==NULL)return 0;
        int lf = f(root->left , ans);
        int rt = f(root->right , ans);
        ans = max(ans , lf+rt+root->val);
        if(max(lf,rt) + root->val < 0)return 0;
        return max(lf,rt)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        f(root,ans);
        return ans;
    }
};