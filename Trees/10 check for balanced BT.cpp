// check for balanced BT

int Balanced(Node *root){
    if(root==NULL) return 0;
    
    int lh = Balanced(root->left);
    if(lh==-1) return -1;
    int rh = Balanced(root->right);
    if(rh==-1) return -1;
    
    if(abs(lh-rh)>1) return -1;
    else return 1+max(lh,rh);
}

bool isBalanced(Node *root){
    return Balanced(root)==-1 ? 0 : 1;
}
