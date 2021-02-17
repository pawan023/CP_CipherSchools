#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
#define Max 1000000007
using namespace std;

// Perfect Sum Problem
// count all subsets of the given array with a sum equal to a given sum. 
/*
Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10}
*/
//1> recursion, exponential time, np complete
int perfectSum(int arr[], int n, int sum){
	//generate all subset, if sum==0, its a valid ans=1, else 0
	if(n==0){
	    return (sum==0) ? 1 : 0;
	}
	//each time we have two choice, either we include element in the set or exclude
    return perfectSum(arr, n-1, sum)+perfectSum(arr, n-1, sum-arr[n-1]);
}
//2> dp O(n*sum) time and space
int perfectSum(int arr[], int n, int sum){
	    int p = 1000000007;
	    int dp[n+1][sum+1] = {};
	    // base case first row = 0; if no eleemnt is thr, cant sum anything to get =S
	    // first column = 1; to make S=0, there is 1 way, to use emopty set, which is always thr
	    for(int i=0; i<=n; i++) dp[i][0] = 1;
	    
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=sum; j++){
	            // we exclude that element
	            if(j<arr[i-1]) dp[i][j] = dp[i-1][j];
	            // we include that element
	            else dp[i][j] = (dp[i-1][j] + dp[i-1][j-arr[i-1]])%p;
	        }
	    }
	    return dp[n][sum];
}
// 3> space improved O(sum), time O(n*Sum)
int perfectSum(int arr[], int n, int sum){
	    int p = 1000000007;
	    int dp[sum+1] = {};
	    // base case first row = 0; if no eleemnt is thr, cant sum anything to get =S
	    // first column = 1; to make S=0, there is 1 way, to use emopty set, which is always thr
	    dp[0] = 1;
	    //since we always use the just above row records, therfore we  use single array
	    for(int i=1; i<=n; i++){
	        for(int j=sum; j>=1; j--){ //fill right to left, in order to not loose past values
	            if(j>=arr[i-1]) dp[j] = (dp[j] + dp[j-arr[i-1]])%p;
	            // we only update when we can use that element/
	            // else we already have past row recods.
	        }
	    }
	    return dp[sum];
	}
//--------------------------------------------------------------------------
// SUBSET SUM problem
/*
Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  
There is a subset (4, 5) with sum 9
*/
bool isSubsetSum(int set[], int n, int sum){ 
    // Base Cases 
    if (sum == 0) return true; 
    if (n == 0) return false; 
    // If last element is greater than sum,then ignore it 
    if (set[n - 1] > sum) 
        return isSubsetSum(set, n - 1, sum); 
    /* else, check if sum can be obtained by any  of the following: 
      (a) including the last element 
      (b) excluding the last element   */
    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]); 
}
bool isSubsetSum(int set[], int n, int sum) 
{ 
    bool subset[n + 1][sum + 1]; 
    for (int i = 0; i <= n; i++) 
        subset[i][0] = true; 
    for (int i = 1; i <= sum; i++) 
        subset[0][i] = false; 
        
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
            if (j < set[i - 1]) 
                subset[i][j] = subset[i - 1][j]; 
            if (j >= set[i - 1]) 
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]]; 
        } 
    } 
    return subset[n][sum]; 
}
//------------------------------------------------------------------------
//variation
// Given a set of numbers, check whether it can be partitioned into 
// two subsets such that the sum of elements in both subsets is same or not.
/*
Following are the two main steps to solve this problem:
1) Calculate sum of the array. If sum is odd, there can not be 
    two subsets with equal sum, so return false.
2) If sum of array elements is even, calculate sum/2 and find 
    a subset of array with sum equal to sum/2.
*/
bool isSubsetSum(int set[], int n, int sum) 
{ 
    bool subset[n + 1][sum + 1]; 
    for (int i = 0; i <= n; i++) 
        subset[i][0] = true; 
    for (int i = 1; i <= sum; i++) 
        subset[0][i] = false; 
        
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
            if (j < set[i - 1]) 
                subset[i][j] = subset[i - 1][j]; 
            if (j >= set[i - 1]) 
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]]; 
        } 
    } 
    return subset[n][sum]; 
} 

bool findPartition(int a[], int n) {
    int sum=0;
    for (int i = 0; i < n; i++) sum+=a[i];
    if(sum%2) return false;
    else return isSubsetSum(a,n,sum/2);
}
//-----------------------------------------
int main()  
{  		
	int tc;
    cin >> tc;
    while (tc--) {
        
        //taking size of array
        int n, i;
        cin >> n;
        int a[n];
        
        //inserting elements in the array
        for (i = 0; i < n; i++) cin >> a[i];

        //calling findPartition() function and
        //printing "YES", if it returns true
        //else "NO"
        if (findPartition(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
} 
