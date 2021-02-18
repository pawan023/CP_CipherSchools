// Detect and remove a loop in the linked list

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void removeLoop(Node* head)
{
    // just remove the loop without losing any nodes
    
    //detecting
    Node *slow=head, *fast=head, *prevSlow=head;
    while(fast && fast->next ){
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) break;//loop occur
    }
    
    if(fast==slow) {//loop  exist
        slow = head;
        //where fast and slow meet again now is the start of loop
        //since we neeed to change pointer of prev of loop entry node
        //we check for fast->next
        if(slow==fast) { prevSlow->next=NULL; return;}
        //boundary case, if the linklist is a circular list
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
}
