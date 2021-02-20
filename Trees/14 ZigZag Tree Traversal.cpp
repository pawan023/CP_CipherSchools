// ZigZag Tree Traversal 

vector <int> zigZagTraversal(Node* root){
    vector<int> zz;
    stack<Node*> s1,s2;
    if(root==NULL) return zz;
    s1.push(root);
    
    while(!s1.empty() or !s2.empty()){
        while(!s1.empty()){
            Node* curr = s1.top();
            s1.pop();
            zz.push_back(curr->data);
            if(curr->left!=NULL) s2.push(curr->left);
            if(curr->right!=NULL) s2.push(curr->right);
        }
        while(!s2.empty()){
            Node* curr = s2.top();
            s2.pop();
            zz.push_back(curr->data);
            if(curr->right!=NULL) s1.push(curr->right);
            if(curr->left!=NULL) s1.push(curr->left);
        }
    }
    return zz;
}
