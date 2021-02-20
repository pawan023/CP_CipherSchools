// Left|Right view of the BT

void printLeft(Node* node, vector<int> &v){
    if(node==NULL) return;
    queue<Node*> q;
    q.push(node);
    // using two loops, inner to print each level
    // outer to switch to diff levels
    while(!q.empty()){
        int count = q.size();// store size before
        // since below loop, curr queue size will incr
        for(int i=0; i<count; i++){
            if(i==0){
                v.push_back(q.front()->data);
            }
            if(q.front()->left  != NULL) q.push(q.front()->left );
            if(q.front()->right != NULL) q.push(q.front()->right);
            q.pop();
        }
    }
}

void printRight(Node* node, vector<int> &v){
    if(node==NULL) return;
    queue<Node*> q;
    q.push(node);
    // using two loops, inner to print each level
    // outer to switch to diff levels
    while(!q.empty()){
        int count = q.size();// store size before
        // since below loop, curr queue size will incr
        for(int i=0; i<count; i++){
            if(i==count-1){
                v.push_back(q.front()->data);
            }
            if(q.front()->left  != NULL) q.push(q.front()->left );
            if(q.front()->right != NULL) q.push(q.front()->right);
            q.pop();
        }
    }
}

