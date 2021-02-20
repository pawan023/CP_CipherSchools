// Construct tree from inorder and postrder traversal

Node *Tree(int in[], int post[], unordered_map<int,int> &mp, int &postIndex, int is, int ie){
    if(is>ie) return NULL; //base case
    // last element of preorder is always the root
    Node *root = new Node(post[postIndex--]); //right to left
    // searching this root element in inorder, to get the right and left subtree
    int inIndex = mp[root->data];
    
    //rcursively call above function for subtree
    // we first go right side, since our post order holds data in tht order
    root->right = Tree(in,post,mp,postIndex,inIndex+1,ie);
    root->left = Tree(in,post,mp,postIndex,is,inIndex-1);
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    // inorder  process root at last, therfore we go right to left in post[]
    int postIndex=n-1;
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        mp[in[i]] = i;
    }
    return Tree(in,post,mp,postIndex,0,n-1);
}
