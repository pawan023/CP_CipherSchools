// Sort a link list of 0s, 1s and 2s

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* segregate(Node *head) {
    
    if(head==NULL or head->next==NULL) return head;
    
    Node *fake0 = new Node(-1);
    Node *fake1 = new Node(-1);
    Node *fake2 = new Node(-1);
    
    Node *zero = fake0, *one = fake1, *two = fake2;
    Node *curr = head;
    
    while(curr){
        if(curr->data==0){
            zero->next = curr;
            curr = curr->next;
            zero = zero->next;
        }
        else if(curr->data==2){
            two->next = curr;
            curr = curr->next;
            two = two->next;
        }
        else{
            one->next = curr;
            curr = curr->next;
            one = one->next;
        }
    }
    //merging these three
    
    zero->next = (fake1->next)? fake1->next: fake2->next;
    // linking o->1 if 1 present else 0->2
    one->next = fake2->next;  // linking 1->2
    two->next = NULL;  // 2->NULL
    //
    head = fake0->next; //new head;
    delete fake0; delete fake1; delete fake2;
    return head;
}

