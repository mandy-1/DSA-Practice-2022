//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// you are required to complete this function
// function should return the size of the 
// Largest Independent set in the tree


//User function template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
int sol(Node* node,unordered_map<Node*,int>& mp){
    if(!node )return 0;
    if(node->left ==NULL && node->right==NULL)return 1;
    if(mp[node])return mp[node];
    int notTake= sol(node->left,mp)+sol(node->right,mp);
    int take=1;
    
    if(node->left){
        if(node->left->left){
            take+=sol(node->left->left,mp);
        }
        if(node->left->right){
            take+=sol(node->left->right,mp);
        }
    }
    if(node->right){
        if(node->right->left){
            take+=sol(node->right->left,mp);
        }
        if(node->right->right){
            take+=sol(node->right->right,mp);
        }
    }
    return mp[node] = max(take,notTake);
}

int LISS(Node *root)
{   
    unordered_map<Node*,int>mp;
    return sol(root,mp);
}


//{ Driver Code Starts.
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
    string treeString;
	getline(cin,treeString);
	Node* root = buildTree(treeString);
    cout<<LISS(root)<<endl;
  }
  return 0;
}

// } Driver Code Ends