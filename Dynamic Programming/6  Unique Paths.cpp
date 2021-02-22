// Unique Paths

#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
#define Max 1000000007
using namespace std;
//  Number of Unique Paths 

//1> recursion, 2^n
int NumberOfPath(int a, int b) {
    // base cases
    // +ve
    if(a==1 && b==1) return 1; // if start=destinatiion, path=1
    // -ve
    if(a<1 || b<1) return 0; // out of boundary = 0 path
    // we start from bottom right cell and go upto top left cell
    // therefore our possible moves chnages to, TOP or LEFT
    // therofore from any cell we can go to 2 directions.
    // top cell or left cell
    return NumberOfPath(a-1,b) + NumberOfPath(a,b-1);
}
//2> dp O(a*b) time and space
int NumberOfPath(int a, int b) {
    // base cases
    int dp[a][b];
    // there is one way to reach cell 0,0 from any cell of 0th row i>e move <--
    for (int i = 0; i < a; i++) 
        dp[i][0] = 1; 
    // there is one way to reach cell 0,0 from any cell of 0th col i>e move ^
    for (int j = 0; j < b; j++) 
        dp[0][j] = 1;
    // for any rest cell, ways = ways(from_leftcell)+ ways(from_topcell);
    for(int i=1;i<a;i++){
        for(int j=1;j<b;j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[a-1][b-1];
}
// 3> space improved O(b)
int NumberOfPath(int a, int b) {
    int dp[b];
    fill(dp,dp+b,1);
    
    for(int i=1;i<a;i++){
        for(int j=1;j<b;j++){
            dp[j] = dp[j-1] + dp[j];
        }
    }
    return dp[b-1];
}
// 4> O(a) time and O(1) space
int nCrModp(int n, int r) {
    if(r>n) return 0; //invalid
    if(r==n or r==0) return 1;
    if(r==n-1 or r==1) return n;
    int p = 1000000007;
    long long ans = 1;
    // here k=r;
    // since, C(n, k) = C(n, n-k)
    if(r > n-r) r = n-r;
    /*
    After simplifying, we get
    C(n, k) = [n * (n-1) * .... * (n-k+1)] / [k * (k-1) * .... * 1]
            = [(n-0) * (n-1) * .... * (n-(k-1)] / [(k-0) * (k-1) * .... * 1]
            //  0 to k-1                            k to 1
    */
    for(int i=0; i<r; i++){
        ans = ( ans*(n-i) )%p;
        ans = ( ans/(i+1) )%p;
    }
    return ans;
}
/*
// since in order to reach final state:
// we need to make sure to move (b-1)times toward right
// && (a-1) times toward down.
// since we are already at (1,1)--->>(a,b)
// now all our diff bath are various combination of these.
// i.e out of a+b-2 we need to choose either (a-1) down or (b-1) right
// both answer will be same, since nCr = nCn-r
// therfore we can just compute , a+b-2Ca-1
*/
int NumberOfPath(int a, int b) {
    return nCrModp(a+b-2,a-1);
}


int main()  
{  		
	int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        
        //calling NumberOfPath() function
        cout << NumberOfPath(a,b) << endl;
    } 
} 
