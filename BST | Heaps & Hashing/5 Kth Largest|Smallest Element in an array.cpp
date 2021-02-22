// Kth Largest|Smallest Element in an array


// Kth largest element 

int KthLargest(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        if (pq.size() == k && pq.top() < arr[i]) { // if size becomes equal to k
            // and top element is smaller than arr[i]
            pq.pop();
            pq.push(arr[i]);
        } else if (pq.size() < k)
            pq.push(arr[i]);
    }

    return pq.top(); // return Kthlargest element
}



// Kth smallest element 

int kthSmallest(int arr[], int n, int k){
    
    priority_queue<int, vector<int>> pq;
    
    for(int i = 0;i<n;i++){
	        if(pq.size() == k){ // if size becomes equal to k
	            if(pq.top() > arr[i]){ // if top element is larger than arr[i]
	                pq.pop();
	                pq.push(arr[i]);
	            }
	        }
	        else if(pq.size() < k){
	            pq.push(arr[i]);
	        }
	    }
	
	return pq.top(); // returns kth smallest element
}

