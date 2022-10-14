//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
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
/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    /*You are required to complete this method*/
    int checkLevelLeafNode(Node* root)
{
    if (!root)
        return 1;
  
    // create a queue for level order traversal
    queue<Node*> q;
    q.push(root);
  
    int result = INT_MAX;
     int level = 0;
 
    // traverse until the queue is empty
    while (!q.empty()) {
        int size = q.size();
        level += 1;
 
        // traverse for complete level
        while(size > 0){
            Node* temp = q.front();
            q.pop();
         
            // check for left child
            if (temp->left) {
                q.push(temp->left);
 
                // if its leaf node
                if(!temp->left->right && !temp->left->left){
 
                    // if it's first leaf node, then update result
                    if (result == INT_MAX)
                        result = level;
                     
                    // if it's not first leaf node, then compare
                    // the level with level of previous leaf node
                    else if (result != level)
                        return 0;                   
                }
            }
              
             // check for right child
            if (temp->right){
                q.push(temp->right);
 
                // if it's leaf node
                if (!temp->right->left && !temp->right->right)
 
                    // if it's first leaf node till now,
                    // then update the result
                    if (result == INT_MAX)
                        result = level;
                     
                    // if it is not the first leaf node,
                    // then compare the level with level
                    // of previous leaf node
                    else if(result != level)
                        return 0;
                     
               }
               size -= 1;
        }   
    }
     
    return 1;
}
    bool check(Node *node)
    {
        return checkLevelLeafNode(node);
    }
};

//{ Driver Code Starts.
// Driver program to test size function
int main()
{
    int t;
    cin>> t;
    getchar();
    while (t--)
    {
        string s;
        getline( cin, s );
        Node* head = buildTree( s );
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}

// } Driver Code Ends