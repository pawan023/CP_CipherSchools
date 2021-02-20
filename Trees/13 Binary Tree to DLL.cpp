// Binary Tree to DLL

Node* DLL(Node *root, Node *&prev){
    //base case
    if(root==NULL) return NULL;
    // simple inorder traversal
    Node *head = DLL(root->left,prev);
    //
    if(prev==NULL) head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    //
    DLL(root->right,prev);
    return head;
}

Node * bToDLL(Node *root){
    Node *prev=NULL;
    return DLL(root,prev);
}
