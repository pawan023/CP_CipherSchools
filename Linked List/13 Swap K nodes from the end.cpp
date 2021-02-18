// Swap Kth nodes from the end

 struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
 };
  
Node *swapkthnode(Node* head, int num, int K)
{
    if(K>num || K==num-K+1 || head==NULL) return head;
    Node *prevA=NULL , *currA=head, *prevB=NULL, *currB=head;
    //getting curr location and prev locationof those nodes A and B
    for(int i=1;i<K;i++){
        prevA = currA;
        currA = currA->next;
    }
    for(int i=1;i<num-K+1;i++){
        prevB = currB;
        currB = currB->next;
    }
    //changing previous pointers
    if(prevA) prevA->next = currB;
    else head = currB;
    if(prevB) prevB->next = currA;
    else head = currA;
    //changing next pointers
    Node *temp = currA->next;
    currA->next = currB->next;
    currB->next = temp;
    
    return head;
}
