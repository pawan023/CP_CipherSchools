// Sum of all nodes of Binary Tree

int sumAllNodes(Node* root) {
    if(root==NULL)  return 0;
    else
      return root->data + sumAllNodes(root->left) + sumAllNodes(root->right);
}
