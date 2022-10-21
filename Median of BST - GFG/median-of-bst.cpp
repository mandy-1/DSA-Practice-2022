//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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



float findMedian(struct Node* node);

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
   Node* root = new Node(stoi(ip[0]));
 
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
           currNode->left = new Node(stoi(currVal));

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
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
#define node Node
#define val data

int fun1(node* root){
    int count=0;
    
    node* curr=root;
    
    while(curr){
        if(!curr->left){
            count++;
            curr=curr->right;
        }
        else{
            node* th=curr->left;
            while(th->right and th->right!=curr){
                th=th->right;
            }
            if(!th->right){
                th->right=curr;
                curr=curr->left;
            }
            else{
                th->right=nullptr;
                count++;
                curr=curr->right;
            }
        }
    }
    return count;
}
float fun2(node* root, int k, int count){
    float ans=-1;
    bool flag=count%2==0 ?true:false;
    
    node* curr=root;
    node* prev=nullptr;
    while(curr){
        
        if(!curr->left)
        {
            k++;
            if(k==count/2+1){
                if(flag){
                    ans=float(prev->val+curr->val)/2;
                    return ans;
                    // break;
                }
                else{
                    ans=curr->val;
                    return ans;
                    
                }
            }
            prev=curr;
            curr=curr->right;
        }
        else{
            node* th=curr->left;
            while(th->right and th->right!=curr){
                th=th->right;
            }
            if(!th->right){
                th->right=curr;
                curr=curr->left;
            }
            else{
                th->right=nullptr;
                k++;
                if(k==count/2+1){
                if(flag){
                    // cout<<"prev="<<prev->val<<endl;
                    // cout<<"curr="<<curr->val<<endl;
                    
                    ans=float(prev->val+curr->val)/2;
                    return ans;
                    // break;
                }
                else{
                    ans=curr->val;
                    return ans;
                    
                }
            }
                prev=curr;
                curr=curr->right;
            }
        }
        
        
    }
    
    
}

float findMedian(struct Node *root)
{
      //Code here
      int count=fun1(root);
    //   cout<<"count="<<count<<endl;
      return fun2(root,0,count);
      
}

