class Solution {
public:
    TreeNode* f(vector<int>& inorder,int instart, int inend, vector<int>& postorder, int         poststart , int postend , map<int,int>& hash){
        if(instart >inend || poststart > postend)return NULL;
        TreeNode* root= new TreeNode(postorder[postend]);
        int temp = hash[root->val];
        int dif = inend - temp;
        root->right = f(inorder,temp+1,inend,postorder,postend-dif,postend-1,hash);
        root->left = f(inorder,instart,temp-1,postorder,poststart,postend-dif-1,hash);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>hash;
        for(int i=0;i<inorder.size();i++){
            hash[inorder[i]] = i;
        }
        return f(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,hash);
    }
};