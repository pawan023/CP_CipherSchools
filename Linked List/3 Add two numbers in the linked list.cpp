// Add two numbers in the linked list

struct Node {
    int data;
    struct Node* next;
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

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    Node *F = reverse(first);
    Node *S = reverse(second);
    Node *res = NULL;
    Node *prev = NULL;
    int carry=0;
    while(F or S){
        int data_F = F!=NULL ? F->data : 0;
        int data_S = S!=NULL ? S->data : 0;
        int sum = (data_F + data_S + carry);
        carry = sum/10;
        sum = sum%10;
        Node *newNode = new Node(sum);
        if(F!=NULL) F = F->next;
        if(S!=NULL) S = S->next;
        if(res==NULL) res = newNode;
        else{
            newNode->next = prev;
        }
        prev = newNode;
        
    }
    if(carry) {
        Node *newNode = new Node(carry);
        newNode->next = prev;
        return newNode;
    }
    else{
        return prev;
    }
}
