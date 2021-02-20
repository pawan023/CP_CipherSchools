// Connect Nodes on the same level

void connect(Node *p){
    Node *root = p;
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        for(int i=0; i<count; i++){
            Node *curr = q.front();
            q.pop();
            
            // for last node of each level set, nextRight = NULL
            if(i==count-1) curr->nextRight = NULL;
            // for rest nodes set, nextRight = its right sibling
            else {
                curr->nextRight = q.front();
            }
            
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        } 
    }
}
