// Intersection point in the linked list

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
   
int intersectPoint(Node* head1, Node* head2)
{
    Node *curr1 = head1, *curr2 = head2;
    int l1=0, l2=0;
    while(curr1){ curr1=curr1->next; l1++; }
    while(curr2){ curr2=curr2->next; l2++; }
    int skip = abs(l1-l2);
    curr1 = head1; curr2 = head2;
    //shift longer list curr "skip" position high
    // and thn compare corresponding element
    if(l1>l2) { while(skip--) curr1=curr1->next; }
    else { while(skip--) curr2=curr2->next; }
    
    while(curr1){
        if(curr1==curr2) return curr1->data;
        curr1=curr1->next;
        curr2=curr2->next;
    }
}
