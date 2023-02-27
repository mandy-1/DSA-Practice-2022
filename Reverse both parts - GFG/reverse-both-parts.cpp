//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
   Node* sol(Node* node,int k,bool flag){
       if(!node)return NULL;
       Node* prev=NULL;
       Node* cur=node;
       Node* next=NULL;
       if(flag){
           while(k--){
               next=cur->next;
               cur->next=prev;
               prev=cur;
               cur=next;
           }           
       }
      else{
          while(cur){
              next=cur->next;
              cur->next=prev;
              prev=cur;
              cur=next;
          }
      }
      
      node->next=sol(cur,k,!flag);
      return prev;
   }
    Node *reverse(Node *head, int k)
    {
        return sol(head,k,true);
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends