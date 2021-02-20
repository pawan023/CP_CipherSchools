// Bottom|top View of BT

//// Bottom|
vector<int> levelOrder(struct Node* node){
    vector<int> v;
    if(node==NULL) return v;
    queue<pair<Node*,int>> q;
    q.push({node,0});
    map<int,int> m;
    while(!q.empty()){
        int count = q.size();
        for(int i=0; i<count; i++){
            Node* currNode = q.front().first;
            int currHD = q.front().second;
            q.pop();
            m[currHD] = currNode->data;
            if(currNode->left != NULL) q.push( {currNode->left, currHD-1} );
            if(currNode->right != NULL) q.push( {currNode->right, currHD+1} );
        }
    }
    
    for(auto x: m)
        v.push_back(x.second);
        
    return v;
}

vector <int> bottomView(Node *root) {
    vector<int> v = levelOrder(root);
    return v;
}

// TOP
vector<int> levelOrder(struct Node* node){
    vector<int> v;
    if(node==NULL) return v;
    queue<pair<Node*,int>> q;
    q.push({node,0});
    map<int,int> m;
    while(!q.empty()){
        int count = q.size();
        for(int i=0; i<count; i++){
            Node* currNode = q.front().first;
            int currHD = q.front().second;
            q.pop();
            m.insert( {currHD,currNode->data} );
            if(currNode->left != NULL) q.push( {currNode->left, currHD-1} );
            if(currNode->right != NULL) q.push( {currNode->right, currHD+1} );
        }
    }
    
    for(auto x: m)
        v.push_back(x.second);
        
    return v;
}

void topView(struct Node *root) {
    vector<int> v = levelOrder(root);
    for(int x: v) cout<<x<<" ";
}

