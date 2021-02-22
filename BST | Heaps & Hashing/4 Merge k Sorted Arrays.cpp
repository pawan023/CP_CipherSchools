// Merge k Sorted Arrays

struct comp{
    bool operator()(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2){
        if(p1.first==p2.first) return p2.second.first>p2.second.first;
        else return p1.first>p2.first;
    }
};

int* mergeKArrays(int arr[][N], int k) {
    // pair<int,pair<int,int>>
    // pair <element,(row,col of that row)>
    priority_queue <pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,comp> pq;
    // create a min heap
    for(int i=0; i<k; i++){
        pq.push({arr[i][0],{i,0}});
    }
    
    int *a = new int[k*k];
    int index = 0;
    
    while(!pq.empty()){
        pair<int,pair<int,int>> temp = pq.top();
        pq.pop();
        int row = temp.second.first;
        int col = temp.second.second;
        a[index++] = temp.first;
        // 0..k-1 is the col range, since we inserting col+1 each time
        // we can go upto k-2
        if(col<k-1) pq.push({arr[row][col+1],{row,col+1}});
    }
    
    return a;
}

