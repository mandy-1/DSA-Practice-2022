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
 TreeNode* buildTreeHelper(vector<int> preorder,vector<int> inorder,int inS,int inE,int preS,int preE)
    {
        if(inS>inE)
        return NULL;
        
        int rootData=preorder[preS];
        TreeNode* root=new TreeNode(rootData);
        int rootIndex=-1;
        for(int i=inS;i<=inE;i++)
        {
            if(inorder[i]==rootData)
            {
                rootIndex=i;
                break;
            }
        }    
        int inleftS=inS;
        int inleftE=rootIndex-1;
        int preleftS=preS+1;
        int preleftE=preleftS+inleftE-inleftS; 
        
        int inrightS=rootIndex+1;
        int inrightE=inE;
        int prerightS=preleftE+1;
        int prerightE=preE;
        
        root->left=buildTreeHelper(preorder,inorder,inleftS,inleftE,preleftS,preleftE);
        root->right=buildTreeHelper(preorder,inorder,inrightS,inrightE,prerightS,prerightE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n=inorder.size();
        return buildTreeHelper(preorder,inorder,0,n-1,0,n-1);       
    }
};