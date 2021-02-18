// Remove duplicate element from sorted Linked List

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node *removeDuplicates(Node *root) {
 Node *curr = root;
 //single node is always sorted
 if(curr->next==NULL) return curr;
 Node *temp = curr->next;
 while(temp){
     //if adjacent node equal, delete temp
     // point temp to next element
     if(curr->data==temp->data){
        curr->next = temp->next;
        temp = temp->next;
     }
     //if adjacent element are diff, increase
     // curr and temp both
     else{
        curr = curr->next;
        temp = temp->next;
     }
 }
    return root;
}

