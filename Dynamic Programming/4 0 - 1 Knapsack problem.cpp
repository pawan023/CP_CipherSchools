// 0 - 1 Knapsack problem

#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
#define Max 100001
using namespace std;

//---------
//  0-1 KNAPSACk problem
//1> recursive 2^n
int knapSack(int W, int wt[], int val[], int n){
   //base cases
   // if no weights avilable, we cant use any.
  //  or if capacity 0, cant pick any
  if(W==0 or n==0) return 0; //W can never be -ve since we check before choosing
  // item, that if it weighs less than or equal to item
   // Your code here
   // recursive calls
   // if ur item weighs <= capacity, itcan be choosen :
   //       so we either vhoose it or we not
   //       and we return max of both choices
   // else we move to next item
   if(wt[n-1]<=W){
       // n reduce by 1 if we dont choose, and also if we choose cuz we can only pick it once
       return max(knapSack(W,wt,val,n-1), val[n-1]+knapSack(W-wt[n-1],wt,val,n-1));
       // if we choose we also lower the capacity, and add its value
   }
   else{
       return knapSack(W,wt,val,n-1);
   }
}
//2>
// dp  O(w*v)time and o(wv) space
// this is not polynomial solution, its a PSEUDO poly. solun
// cuz W can be very large in some casesm there this solution will be worse than 2^n
// knapsack is a hard CS prob, comes in np hard problem
int knapSack(int W, int wt[], int val[], int n){
   //base cases
   int dp[n+1][W+1] = {}; // all zero
   //each cell represetn max value we can achieve with first i items and j capacity
   for(int i=1;i<=n;i++){
       for(int j=1;j<=W;j++){
           if(wt[i-1]<=j){ // item are in i-1 index
               dp[i][j] = max( dp[i-1][j] , val[i-1]+dp[i-1][j-wt[i-1]] );
           }
           else{
               dp[i][j] = dp[i-1][j];
           }
       }
   }
   return dp[n][W];
}
//3> O(n)time o(1) space
int knapSack(int W, int wt[], int val[], int n){
   //base cases
   int dp[W+1] = {}; // all zero
   //each cell represetn max value we can achieve with first i items and j capacity
   for(int i=1;i<=n;i++){
       //start from the end since 1 item can be used only once
       // if we go left to right our future result which are using past result, 
       // both can use the same item 2or,or time
       for(int j=W;j>=wt[i-1];j--){
            if(wt[i-1]<=j)
                dp[j] = max( dp[j] , val[i-1] + dp[j-wt[i-1]] );
       }
   }
   return dp[W];
}
int main(){
	FAST_IO
	int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
}
