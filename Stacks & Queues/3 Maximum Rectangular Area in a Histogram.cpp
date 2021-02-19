// Maximum Rectangular Area in a Histogram

long long getMaxArea(long long hist[], long long n){
    
    stack<long long> s;
    long long maxArea = INT_MIN;
    //for ht's having a next smaller ht.
    for(int i=0; i<n; i++){
        while(!s.empty() && hist[s.top()]>=hist[i]) {
            long long ht = s.top(); s.pop();
            long long width = s.empty() ? i : (i-s.top()-1);
            maxArea = max(maxArea, (hist[ht]*width));
        }
        s.push(i);
    }
    //for ht's NOT having a next smaller ht.
    while(!s.empty()){
        long long ht = s.top(); s.pop();
        long long width = s.empty() ? n : (n-s.top()-1);
        maxArea = max(maxArea, (hist[ht]*width));
    }
    return maxArea; 
}
