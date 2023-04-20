//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    unordered_map<Node*,Node*>mp;
    Node* key=NULL;
    void dfs(Node* node,Node* parent,int& home){
        if(!node)return;
        if(node->data==home) key=node;
        if(parent)
            mp[node]=parent;
        dfs(node->left,node,home);
        dfs(node->right,node,home);
    }
    
    int ladoos(Node* root, int home, int k)
    {
        dfs(root,NULL,home);
        if(!key)return 0;
        int ans=0;
        queue<Node*>q;
        q.push(key);
        int cnt=0;
        unordered_map<Node*,bool>vis;
        vis[key]=1;
        while(!q.empty()){
            if(cnt>k)break;
            // cout<<q.size()<<" "<<cnt<<endl;
            int n=q.size();
            for(int i=0;i<n;i++){
                
                Node* node=q.front();
                // cout<<node->data<<" "<<cnt<<endl;
                q.pop();
                ans+=node->data;
                if(node->left && !vis[node->left]){
                    
                    q.push(node->left);
                    vis[node->left]=1;
                }
                if(node->right && !vis[node->right]){
                    
                    q.push(node->right);
                    vis[node->right]=1;
                }
                if(mp[node] && !vis[mp[node]]){
                    
                    q.push(mp[node]);
                    vis[mp[node]]=1;
                }
            }
            cnt++;
        }
        return ans;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends