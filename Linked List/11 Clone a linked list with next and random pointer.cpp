// Clone a linked list with next and random pointer

struct Node
{
  int data;
  Node* next;
  Node* arb;
};

Node *copyList(Node *head)
{
    if (head == NULL) return head;

    Node *t = head;
    while (t != NULL)
    {
        // making an identical list merged with original list
        Node *n = new Node(t->data);
        n->next = t->next;
        t->next = n;
        t = n->next;
    }
    
    t = head;
    Node *head2 = head->next;   // variable to be returned
    while (t != NULL)
    {
        // setting the arbitary pointers of duplicate list
        if (t->arb == NULL)
            t->next->arb = NULL;
        else 
            t->next->arb = t->arb->next;
        
        t = t->next->next;
    }
    
    t = head;
    while (t != NULL)
    {
        // separating the 2 merged lists (duplicate and original)
        head = t->next->next;
        
        if(head) t->next->next = head->next;
        else t->next->next = NULL;
        
        t->next = head;
        t = head;
    }

    return head2;
}

