// Diameter of Binary Tree

int height(Node *root, int &maxPath){
	if(root==NULL) return 0;
	int lh = height(root->left,maxPath);
	int rh = height(root->right,maxPath);
	maxPath = max(maxPath , 1+lh+rh);
	return 1+max(lh,rh);
}

int diameter(Node* node) {
    if(node==NULL) return 0;
    int maxPath = INT_MIN;
    height(node,maxPath);
    return maxPath;
}
