// Mirror Tree / Identical tree


// Given a Binary Tree, convert it into its mirror.

void mirror(Node* node) {
    Node* root = node;
    if(root!=NULL){
        // swap left and right child of curr parent
        swap(root->left,root->right);
        // recursively call for left & right child
        mirror(root->left);
        mirror(root->right);
    }
}

// find if both of them are identical or not. 

bool isIdentical(Node *r1, Node *r2){
    // if both are empty
    if(r1==NULL && r2==NULL) return true; 
    // if both are non empty
    if(r1!=NULL && r2!=NULL){
        if(r1->data != r2->data) return false;
        bool l = isIdentical(r1->left,r2->left);
        bool r = isIdentical(r1->right,r2->right);
        return l&&r;
    }
    // if either one is empty and other is not 
    else return false;
}
