// Print the largest element in every k window

//1 using stacks
vector <int> max_of_subarrays(int *arr, int n, int k){
    stack<int> s;
    vector<long long> nle(n,n);
    s.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() and arr[i]>=arr[s.top()]) { s.pop(); }
        if(s.empty()) nle[i]=n;
        else nle[i]=s.top();
        s.push(i);
    }
    int j=0;
    vector<int> v(n-k+1,0);
    for(int i=0;i<=n-k;i++){
            if(j<i) j=i;
            while(nle[j]<i+k) { j=nle[j]; }
            v[i] = arr[j];
    }
    return v;
}

//2 using deque
vector <int> max_of_subarrays(int *arr, int n, int k){
    stack<int> s;
    vector<long long> nle(n,n);
    s.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() and arr[i]>=arr[s.top()]) { s.pop(); }
        if(s.empty()) nle[i]=n;
        else nle[i]=s.top();
        s.push(i);
    }
    int j=0;
    vector<int> v(n-k+1,0);
    for(int i=0;i<=n-k;i++){
            if(j<i) j=i;
            while(nle[j]<i+k) { j=nle[j]; }
            v[i] = arr[j];
    }
    return v;
}
