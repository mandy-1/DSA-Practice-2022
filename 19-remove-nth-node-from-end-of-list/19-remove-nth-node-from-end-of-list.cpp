class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        if(cnt==n){
            return head->next;
        }
        if(cnt==1 && n==1)return NULL;
        cnt = cnt-n-1;
        temp=head;
        while(cnt>0){
            temp = temp->next;
            cnt--; 
        }
        temp->next =temp->next->next;
    return head;
    }
    
};