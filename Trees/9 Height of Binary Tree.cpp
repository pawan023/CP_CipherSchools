// Height of Binary Tree

int height(Node* root) {
    if(root==NULL) { return 0; }
    else{
      return 1+max( height(root->left),height(root->right) );
    }
}
