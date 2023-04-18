//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
bool isBst(Node* root,int &prev,int &sum,int &cnt){
        if(root==NULL){
            return  true;
        }
       if( !isBst(root->left,prev,sum,cnt)){
           return false;
       }
        if(prev>=root->data){
            return false;
        }
        sum+=root->data;
        cnt++;
        prev=root->data;
        return isBst(root->right,prev,sum,cnt);
       return true;
    }
    void dfs(Node *root,int target,int &ans){
        if(root==NULL){
            return;
        }
        int sum=0;
        int cnt=0;
        int prev=-1;
        if(isBst(root,prev,sum,cnt)){
            if(sum==target){
                ans=min(ans,cnt);
            }
        }
        dfs(root->left,target,ans);
        
        dfs(root->right,target,ans);
        
    }
    int minSubtreeSumBST(int target, Node *root) {
        // code here
        int ans=INT_MAX;
        dfs(root,target,ans);
        return ans==INT_MAX?-1:ans;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends