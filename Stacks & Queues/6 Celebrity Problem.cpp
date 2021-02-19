// Celebrity Problem

class Solution {
    public:
    int celebrity(vector<vector<int> >& M, int n) {
        // code here 
        int a=0, b=n-1;
    	// eliminate invalid candidates, untill 1 is left
    	while(a<b){
    		if(M[a][b]==1) a++; // a knows b
    		else b++; // b knows a
    	}
    	// the last candidate need through checking
    	for(int i=0; i<n; i++){
    		if(i!=a && (M[i][a]==0 or M[a][i]==1)) return -1;
    	}
    	return a;
    }
};
