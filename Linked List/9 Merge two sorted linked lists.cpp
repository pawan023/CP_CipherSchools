// Merge two sorted linked lists

// Recursive
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

// Iterative
Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    Node *fake = new Node(-1);
    Node *last = fake;
    while(head_A && head_B){
        if(head_A->data<=head_B->data){
            last->next = head_A;
            last = head_A;
            head_A = head_A->next;
        }
        else{
            last->next = head_B;
            last = head_B;
            head_B = head_B->next;
        }
    }
    if(head_A){
        last->next = head_A;
    }
    else{
        last->next = head_A;
    }
    return fake->next;
}  
