//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s)
    {
        vector<int>mp(26,0),mp2(26,0);
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }
        vector<Node*>ans;
        int cnt=0;
        Node* first = head;
        Node* last = head;
        Node* prev = head;
        while(last){
            if(cnt<n){
                mp2[last->data -'a']++;
                prev=last;
                last=last->next;
                cnt++;
            }
            else if(cnt==n && mp2==mp){
                ans.push_back(first);
                prev->next=NULL;
                first=last;
                prev=last;
                cnt=0;
                for(int i=0;i<26;i++){
                    mp2[i]=0;
                }
            }
            else{
                mp2[first->data - 'a']--;
                mp2[last->data - 'a']++;
                first=first->next;
                prev=last;
                last=last->next;
            }
        }
        // cout<<cnt;
        if(cnt == n && mp2==mp){
            ans.push_back(first);
            prev->next=NULL;   
        }
        return ans;

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends