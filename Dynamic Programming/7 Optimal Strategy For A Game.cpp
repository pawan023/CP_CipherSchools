////  Optimal Strategy For A Game

#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
#define Max 100001
using namespace std;

//---------
//  Optimal Strategy For A Game
//1> recursive 2^n
long long strategy(int arr[], int i, int j){ // i&j are indexes o to n-1
    // base case, when only two eleemnts are left return max of them
    if( j == i+1 ) return max(arr[i],arr[j]);
    // at every instance we have two choices, either we take 
    // ith element or jth element, whoever result in global max result
    // now after choosing one of the above element, the opponent will also
    // choose the same strategy to get global max of rest.
    // therefore opponent chossing max == we choosing min from left space
    long long op1 = arr[i] + min( strategy(arr,i+2,j), strategy(arr,i+1,j-1) );
    //    i  i+1  i+2 ......... j-2  j-1   j
    //    U  opp  |                        |
    //    U  |                        |   opp
    long long op2 = arr[j] + min( strategy(arr,i+1,j-1), strategy(arr,i,j-2) );
    //    i  i+1  i+2 ......... j-2  j-1   j
    //   opp  |                        |   U
    //    |                      |    opp  U
    return max(op1,op2);
    //return max of both option

}
//2>A>
// dp  O(n*n)time and o(n*n) space
long long maximumAmount(int arr[], int n) {
    int dp[n][n] = {};
    //base case,
    // if only 2,choose max of 2 elements
    // fill this on diagonal above mid diagonal
    for(int i=0; i<n-1; i++){ //n-1
        dp[i][i+1] = max(arr[i],arr[i+1]);
    }
    //in each row we skip adjacent diagonal
    // since we can observe that our func call are not to
    // adjacent diagonal cell
    // also we may go out of bound index 
    // if we do all diagonal
    for(int gap=3; gap<n ;gap=gap+2){
        for(int i=0; i+gap<n; i++){
            int j=i+gap;
            dp[i][j] = max( arr[i] + min(dp[i+2][j], dp[i+1][j-1]), 
                            arr[j] + min(dp[i+1][j-1], dp[i][j-2]) );
        }
    }
    return dp[0][n-1];
    
    /*
    //
    20  5  4  6  8  3 //input
    
    //dp
    0   1  2  3  4  5 //index
        20    25    32
           5     13
              6     12
                 8
                    8
    */
}

int main(){
	FAST_IO
	int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
}
