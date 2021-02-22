// Heap Sort

void heapify(int arr[], int n, int i)  {
    while(true){
        int largest = i, left = 2*i+1, right = 2*i+2;
    	if(left<n && arr[left]>arr[largest]) largest=left;
    	if(right<n && arr[right]>arr[largest]) largest=right;
    	if(largest!=i){
    		swap(arr[i],arr[largest]);
    		i=largest;
    	}
    	else break;
    }
}

void buildHeap(int arr[], int n)  {
    for(int i=(n-2)/2; i>=0; i--){
		heapify(arr,n,i);
	}
}
