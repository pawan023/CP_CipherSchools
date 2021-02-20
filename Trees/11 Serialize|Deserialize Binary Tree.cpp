// Serialize|Deserialize Binary Tree

void serialize(Node *root,vector<int> &A){
    if(root==NULL) {
        A.push_back(-1); 
        return;
    }
    A.push_back(root->data);
    serialize(root->left,A);
    serialize(root->right,A);
}

Node * DeSerialize(vector<int> &A,int &index){
    /* optional base case, but in thsi case , we will already return before
    // index eaches out of bound
    if(index == A.size()) {
        return NULL;
    }*/
    int value = A[index++];
    if(value == -1) {
        return NULL;
    }
    Node *root = new Node(value);
    root->left = DeSerialize(A,index);
    root->right = DeSerialize(A,index);
    return root;
}

Node * deSerialize(vector<int> &A){
    int index=0;
    DeSerialize(A,index);
}
