// Level Order Traversal to BST 

struct info{
    Node *ptr;
    int min, max;
};

Node* constructBst(int arr[], int n){
    if(n==0) return NULL;
    
    queue<info> q;
    int i=0;
    info temp;
    temp.ptr = new Node(arr[i++]);
    temp.min = INT_MIN;
    temp.max = INT_MAX;
    q.push(temp);
    
    Node *root = temp.ptr;
    
    while(i<n){
        info curr = q.front();
        q.pop();
        
        if(i<n && arr[i]<curr.ptr->data && arr[i]>curr.min){
            temp.ptr = new Node(arr[i++]);
            temp.min = curr.min;
            temp.max = curr.ptr->data;
            curr.ptr->left = temp.ptr;
            q.push(temp);
        }
        
        if(i<n && arr[i]>curr.ptr->data && arr[i]<curr.max){
            temp.ptr = new Node(arr[i++]);
            temp.min = curr.ptr->data;
            temp.max = curr.max;
            curr.ptr->right = temp.ptr;
            q.push(temp);
        }
    }
    
    return root;
}

