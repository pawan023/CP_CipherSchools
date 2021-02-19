// Circular tour

int tour(petrolPump p[],int n) {
    int prev=0, curr=0,start=0; 
    for(int i=0; i<n; i++){
        curr += (p[i].petrol-p[i].distance);
        if(curr<0){
            start=i+1;
            prev+=curr;
            curr=0;
        }
    }
    return (prev+curr>=0)? start : -1;
}
