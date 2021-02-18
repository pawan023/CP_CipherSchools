// Reorder Linked List

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head or !head->next) return;
        
        //step1) find mid
        ListNode *slow=head, *fast=head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid= slow->next;
        slow->next=NULL;
        //step2)  reverse second half
        ListNode *curr=mid, *prev=NULL;
        while(curr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode *newhead = prev;
        //step3) merge correspsondingelement of both halfs one my one
        ListNode *curr1 = head, *curr2 = newhead;
        while(curr2){
            ListNode *temp1 = curr1->next;
            curr1->next = curr2;
            ListNode *temp2 = curr2->next;
            curr2->next = temp1;
            curr1 = temp1;
            curr2 = temp2;
        }
        //for odd len
        if(curr1) curr1->next=NULL;
    }
};

