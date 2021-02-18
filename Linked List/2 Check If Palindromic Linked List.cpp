// Check If Palindromic Linked List

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

struct Node * reverse(struct Node * head){
    Node *prev=NULL, *curr=head;
    while(curr){
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    //Your code here
    if(head==NULL or head->next==NULL) return true;
    Node *slow = head, *fast = head;
    //conditions are to get first middle
    while(fast->next && fast->next->next){ //conditions r crucial
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *revHead = reverse(slow->next);
    Node *curr1 = head, *curr2 = revHead;
    while(curr2){
        if(curr1->data != curr2->data) return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return true;
}

