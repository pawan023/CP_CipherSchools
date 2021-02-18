// Sort a linked list

Node* merge(Node* a, Node* b) {
    if(a == NULL) return b;
    else if(b == NULL) return a;
    Node* c;
    if(a->data < b->data) {
        c  = a;
        c->next = merge(a->next, b);
    }
    else {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

Node* midNode(Node* head){
    Node *slow=head, *fast=head;
    //to get first mid in even nodes
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSort(Node* head) {
    // your code here
    //base case
    if(head==NULL or head->next==NULL) return head;
    
    Node *mid = midNode(head);
    Node *x = head;
    Node *y = mid->next;
    mid->next = NULL;
    
    x = mergeSort(x);
    y = mergeSort(y);
    
    Node* z = merge(x,y);
    return z;
    
}

