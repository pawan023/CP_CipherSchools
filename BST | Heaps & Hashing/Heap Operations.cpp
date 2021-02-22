// Heap Operations

struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    int parent(int i);
    int left(int i);
    int right(int i);
};

void MinHeap::insertKey(int k) {
    if(heap_size==capacity) return;
    heap_size++;
    harr[heap_size-1] = k;
    int i = heap_size-1;
    while(i!=0 && harr[(i-1)/2]>harr[i]){
        swap(harr[(i-1)/2],harr[i]);
        i = (i-1)/2;
    }
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::extractMin() {
    if(heap_size<=0) return -1;
    if(heap_size==1) {
        heap_size--;
        return harr[0];
    }
    int min = harr[0];
    swap(harr[0],harr[heap_size-1]);
    heap_size--;
    MinHeapify(0);
    return min;
}

void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::deleteKey(int i) {
    if(i>=heap_size) return;
    decreaseKey(i,INT_MIN);
    extractMin();
}

