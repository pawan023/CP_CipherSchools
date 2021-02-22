// Binomial cofficent nCr

#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
#define Max 1000000007
using namespace std;
//---------
//  nCr 
//1> recursive 2^n
int nCrModp(int n, int r) {
    //base case +ve and -ve
    if(r==0) return 1; // selecting 0 student, is easy.. dont pick any = 1way
    if(n==0) return 0; // selcting a student from no student.. is impossible = 0 way
    //selecting r student from n student cane be done by ,
    // either selecting 1 student or not selecting it and repeating this 
    // till u get n student selected.
    // ncr = rejecting ith student + selecting ith student 
    // ncr = n-1cr + n-1cr-1
    return nCrModp(n-1,r) + nCrModp(n-1,r-1);
} 
//2>
// dp  O(n*r)time and o(n*r) space
int nCrModp(int n, int r) {
    int p = 1000000007;
    long long dp[n+1][r+1] = {};
    // first col== 0, since 0 item can be selected in 1 way //base case
    // all daig\ = 1, since ncn = 1, all can be selected from all in 1 way
    // all cell above diag = 0, since selecting 5 student from 4 i.e r>n is invalid
    //while filling dp[i][j]
    for(int i=0; i<=n; i++) dp[i][0] = 1;
    
    for(int i=1; i<=n; i++){// start from 1st row to nth row
    // we cant always go till j=i, if r<n. therefore we go tilll min(i,r)
        for(int j=1; j<=min(i,r); j++){ // start from 1st colu to ith col, >i =0
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] )%p;
        }
    }
    return dp[n][r];
} 
    
    /*
    
    //dp
    0   1   2   3   4    //index
    1	0	0	0	0	
    1	1	0	0	0	
    1	2	1	0	0	
    1	3	3	1	0 	
    1	4	6	4	1	
    
    */
}
//3> dp  O(n*r)time and o(r) space
int nCrModp(int n, int r) {
    int p = 1000000007;
    long long dp[r+1] = {};
    dp[0] = 1;
    // filling the dp from right to left
    // since we need result of above row, and we will be updating
    // above row if we go left to right
    for(int i=1; i<=n; i++){// start from 1st row to nth row
        // we will go till j=1, since we lf j-1 index, we go out of bound
        for(int j=min(i,r); j!=0; j--){ 
            dp[j] = (dp[j] + dp[j-1])%p;
        }
    }
    return dp[r];
} 
//4> O(r)time and O(1) space
// DOESNT WORK WITH LARGE INPUT, RANDOM ANS;
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

int main(){
	FAST_IO
	int t, n, r;
  cin >> t;
  
  while(t--){
      cin >> n >> r;
      cout << nCrModp(n, r) << endl;
  }
  
  return 0;
}
