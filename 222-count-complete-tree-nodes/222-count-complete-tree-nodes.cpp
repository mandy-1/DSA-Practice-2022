class Solution {
public:
    int findHeightLeft(TreeNode* node){
        if(node == NULL)return 0;
        int ht =0 ;
        while(node){
            ht++;
            node = node->left;
        }
        return ht;
    }
    
    int findHeightRight(TreeNode* node){
        if(node == NULL)return 0;
        int ht =0 ;
        while(node){
            ht++;
            node = node->right;
        }
        return ht;
    }    
    
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0 ;
        int lf = findHeightLeft(root);
        int rt = findHeightRight(root);
        
        if(lf == rt) return (1 << rt) - 1;
        return( 1 + countNodes(root->left) + countNodes(root->right));
    }
};