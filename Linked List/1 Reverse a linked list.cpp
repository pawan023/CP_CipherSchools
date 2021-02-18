// Reverse a linked list

struct Node
{
    int data;
    struct Node *next;
};

//1
struct Node* reverse(struct Node *curr, struct Node *prev){
    if(curr==NULL) return prev;
    if(curr->next==NULL) return curr;
    Node *next = curr->next;
    curr->next = prev;
    return reverse(curr,next);
}
struct Node* reverseList(struct Node *head)
{
    Node *prev=NULL, *curr=head;
    return reverse(curr,prev);
}

//2
struct Node* reverseList(struct Node *head)
{
    if(head==NULL or head->next==NULL) return head;
    
    Node *rest_head = reverseList(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    
    return rest_head;
}

//3
struct Node* reverseList(struct Node *head)
{
    Node *prev=NULL, *curr=head;
    while(curr){
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
