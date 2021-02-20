// BT Traversals

void preorderTraversal(vector<int> &v, Node *root){
	if(root!=NULL){
		v.push_back(root->data);
		preorderTraversal(v,root->left);
		preorderTraversal(v,root->right);
	}
}

void inorderTraversal(vector<int> &v, Node *root){
	if(root!=NULL){
		inorderTraversal(v,root->left);
		v.push_back(root->data);
		inorderTraversal(v,root->right);
	}
}

void postTraversal(vector<int> &v, Node *root){
	if(root!=NULL){
		postTraversal(v,root->left);
		postTraversal(v,root->right);
		v.push_back(root->data);
	}
}

vector<vector<int>> levelOrder(Node* node){
    vector<vector<int>> levels;
    vector<int> v;
    queue<Node*> q;
    if(node==NULL) return levels;
    q.push(node);
    // using two loops, inner to print each level
    // outer to switch to diff levels
    while(!q.empty()){
        int count = q.size(); // store size before
        // since below loop, curr queue size will incr
        for(int i=0; i<count; i++){
            v.push_back(q.front()->data);
            if(q.front()->left  != NULL) q.push(q.front()->left );
            if(q.front()->right != NULL) q.push(q.front()->right);
            q.pop();
        }
        levels.push_back(v);
        v.clear();
    }
    return levels;
}

