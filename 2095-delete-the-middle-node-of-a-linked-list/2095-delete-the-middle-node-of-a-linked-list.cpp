class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        if(head->next->next==NULL){
            head->next=NULL;
            return head;
        }
        ListNode* s=head;
        ListNode* f=head;
        int c=0;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        ListNode* temp=head;
        while(temp->next!=s){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};