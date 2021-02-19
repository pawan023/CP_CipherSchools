//  Next Greater Element in Array

vector <long long> nextLargerElement(long long arr[], int n){
    stack<long long> s;
    vector<long long> nge(n,1);
    for(int i=n-1; i>=0; i--){
        while(!s.empty() and s.top()<=arr[i])
            s.pop();
        nge[i] = (s.empty())? -1: s.top();
        s.push(arr[i]);
    }
    return nge;
}
