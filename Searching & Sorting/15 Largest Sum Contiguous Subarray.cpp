#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
#define Max 1000000007
#define ll long long
using namespace std;
// kadane algo 1
// finding maxsum so far
// O(n) time and space

long long maximumSum(int arr[], int sizeOfArray){
   //print corresponding values and at the end print next line and return the maximum sum
   int n = sizeOfArray;
   int dp[n];
   dp[0]=arr[0];// a single no is already max
   int MAX = dp[0]; // min len=1
   for(int i=1; i<n; i++){
       // at each i, we got two choices.
       // either to include this no, in max_sum_so_far, or not include.
       dp[i] = max(arr[i], arr[i]+dp[i-1]);
       MAX = max(dp[i],MAX);
   }
   return MAX;
}
// O(1) space 
long long maximumSum(int arr[], int sizeOfArray){
   int n = sizeOfArray;
  // a single no is already max
   int MAX = arr[0], prev = arr[0]; // min len=1
   for(int i=1; i<n; i++){
       // at each i, we got two choices.
       // either to include this no, in max_sum_so_far, or not include.
        prev = max(arr[i], arr[i]+prev);
        MAX = max(prev,MAX);
   }
   return MAX;
}
// kadens algo variations:":
//2>kadane algo 2, find max sum subbray with no adjacent element
// no can be -ve also
long long maximumSum(int arr[], int sizeOfArray){
    int n = sizeOfArray;
    if(n<1) return 0;
    if(n==1) return arr[0];
    if(n==2) return max(arr[0],arr[1]);
    int dp[n];
    dp[0]=arr[0], dp[1]=max(arr[0],arr[1]);
    int MAX = max(arr[0],arr[1]);
    for(int i=2; i<n; i++){
        // at each i, we got 4 choices.
        // 1>choosing ith:
        // go with just the ith eleemnt itself, arr[i]
        // go with ih + max_sum_so_far_not_adjacent. arr[i]+dp[i-2]
        // 2>not choosing ith no
        // go with max_sum_so_far_not_adjacent. dp[i-1]
        // go with max_sum_so_far_adjacent. dp[i-2]
        dp[i] = max( arr[i] , max( arr[i]+dp[i-2], max(dp[i-1], dp[i-2]) ) );
        MAX = max(dp[i],MAX);
    }
    return MAX;
}
// 3> Max sum subarray by removing at most one element 
/*
If element removal condition is not applied, we can solve this problem using 
Kadane’s algorithm but here one element can be removed also for increasing maximum sum. 
This condition can be handled using two arrays, forward and backward array, 
these arrays store the current maximum subarray sum from starting to ith index, 
and from ith index to ending respectively.
In below code, two loops are written, first one stores maximum current sum in forward direction 
in fw[] and other loop stores the same in backward direction in bw[]. 
Getting current maximum and updation is same as Kadane’s algorithm.
Now when both arrays are created, we can use them for one element removal conditions as follows,
at each index i, maximum subarray sum after ignoring i’th element will be fw[i-1] + bw[i+1] 
so we loop for all possible i values and we choose maximum among them.
Total time complexity and space complexity of solution is O(N)
*/ 
int maxSumSubarray(int A[], int n){
    int fw[n];
    fw[0]=A[0];
    int Maximum = A[0];
    for(int i=1; i<n; i++){
        fw[i] = max( A[i], A[i]+fw[i-1] );
        Maximum = max(Maximum,fw[i]);
    }
    int bw[n];
    bw[n-1]=A[n-1];
    for(int i=n-2; i>=0; i--){
        bw[i] = max( A[i], A[i]+bw[i+1] );
    }
    /*
    Note: You have to first find the maximum sub-array sum and then remove the 
    element from that sub-array if necessary. 
    Also after removal, the sub-array size should at least be 1
    */
    for(int i=1; i<n-1; i++){
        Maximum = max( Maximum, fw[i-1]+bw[i+1]);
    }
    return Maximum;
}

int main() 
{ 
    	int sizeOfArray;
	    cin>>sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    //inserting elements to the array
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    //calling function maximumSum()
	    cout<<maximumSum(arr,sizeOfArray)<<endl; 
} 
  
