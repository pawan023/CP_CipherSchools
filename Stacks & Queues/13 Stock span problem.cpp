// Stock span problem 

vector <int> calculateSpan(int price[], int n)
{
   // Your code here
    stack<int> s;
    vector<int> pse(n,1);
    for(int i=0; i<n; i++){
        while(!s.empty() && price[s.top()]<=price[i])
            s.pop();
        pse[i] = (s.empty())? i+1 : i-s.top();
        s.push(i);
    }
    return pse;
}
