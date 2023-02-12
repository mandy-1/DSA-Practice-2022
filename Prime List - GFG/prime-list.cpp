//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    bool isprime(int& i){
        if(i==1)return true;
        for(int k=2;k<=sqrt(i);k++){
            if(i%k==0)return false;
        }
        return true;
    }
    int sol(int& n){
        int temp=n;
        while(temp>=sqrt(n)){
            if(isprime(temp))return temp;
            temp--;
        }
        return 2;
    }
    int sol2(int& n){
        int temp=n;
        while(temp<=10007){
            if(isprime(temp))return temp;
            temp++;
        }
        return 2;
    }

    Node *primeList(Node *head){
        Node* temp=head;
        while(temp){
            if(temp->val==1){
                temp->val=2;
            }
            else{
              int n1=sol(temp->val);
              int n2=sol2(temp->val);
              temp->val=abs(temp->val-n1)<=abs(temp->val-n2)?n1:n2;
            }
              temp=temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends