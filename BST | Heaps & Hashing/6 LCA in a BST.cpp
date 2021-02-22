// Lowest Common Ancestor in a BST

Node* LCA(Node *root, int n1, int n2){
    Node *curr=root;
    
    while(curr!=NULL){
        if(curr->data<n1 && curr->data<n2)
            curr = curr->right;
        else if(curr->data>n1 && curr->data>n2)
            curr = curr->left;
        else
            return curr;
    }
    // control comes here if empty tree or nodes are not present
    return NULL;
}
