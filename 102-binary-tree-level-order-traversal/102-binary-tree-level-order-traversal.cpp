class Solution {
public:
vector<vector<int>> levelOrder(TreeNode* root) {
        queue<vector<TreeNode* >> q;
        vector<TreeNode*> cur_lvl;
        cur_lvl.push_back(root);
        q.push(cur_lvl);  //push root into the queue as vector
        
        vector<vector<int>> ans;
        
        while(!q.empty())
        {
            vector<TreeNode*> cl = q.front(); // pop out the first element from the queue and store in current level
            q.pop();
            vector<int> cld; //vector to store the corresponding integer value
            int i=0;
            int j=cl.size();
            vector<TreeNode*> nl; //next level vector
            
            while(i<j){ // traverse the current level vector
                if(cl[i]){
                    cld.push_back(cl[i]->val); 
                    nl.push_back(cl[i]->left); 
                    nl.push_back(cl[i]->right);
                }
                i++;
            }
            
            if(nl.size()!=0){ // if next level has no element then continue to next iteration
                q.push(nl); //push next level into the queue
                ans.push_back(cld);
            }
        }
        
        return ans;
    }
};