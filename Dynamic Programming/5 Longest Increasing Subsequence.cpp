// Longest Increasing Subsequence

#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
#define Max 100001
using namespace std;
/* 	 let , l = len of LIS;
	variations:
	1> min del to make an array sorted, (n-l)
	2> maximum sum increasing subseq
	//
	int MaxSumIncreasingSubsequence(int n, int a[])
	{
	   // your code here
		if(n==0) return 0;
		int dp[n] ;
		fill(dp,dp+n,INT_MIN);
		dp[0] = a[0];
		int sum = a[0];
		for(int i=1;i<n;i++){
			for(int j=i-1; j>=0; j--){ // each index store LIS, from 0 to i
				if(a[i]>a[j]) dp[i] = max(dp[i], a[i]+dp[j]);
				if(dp[i]>sum) sum = dp[i];   
			}
		}
		return sum;
	}
	//
	3> Max len(l) bitonic subseq = a subseq which is first incr thn decr;
	   inc or dec past can be 0
	    1 2 3, l=3 // decr part = 0
	    3 2 1, l=3 // incr part = 0
	    logic is to calculate lIS from left to right, lIS ending at ith index
	    and LDS = LIS from right to left,
	    // now for any element i as pivot, lis holds the incr subseq from 0..i and lds holds dec subseq from i..n-1
	    
	    now to find bitonic subseq, traverse array again and, calculate for each index, ( lis(i) + lds(i) -1 ), since the pivot element
	    occur in both subseq
	4> BUilding bridges, O(nlogn) time  sorting+lis
		given pair of points(a,b), denoting city a on lane 1 amd city b on lane 2. u neeed to
		make maximise the no of bridges u can make, such that no 2 bridge cross each other.
		Logic: 2 steps
		1>is to sort the pair, accoding to first value i.e a. and for two points having (a,b) and (a,c)
		sort as per smallest second value.
		2> find the LIS with the second value of each sorted pair.
		3> len(LIS) is our ans
	5> Longest chain of pairs, here(a,b) a<b
		1>is to sort the pair, accoding to first value
		2> find the LIS with the second value  ofi-th pair & first value of ith pair .
		3> len(LIS) is our ans		
*/
//1> dp o(n*n)
int longestSubsequence(int n, int a[])
{
   // your code here
	if(n==0) return 0;
	int dp[n] ;
	fill(dp,dp+n,1); // a single char is always increasing
	int len = 1;
	for(int i=0;i<n;i++){
		for(int j=i-1; j>=0; j--){ // each index store LIS, from 0 to i
			if(a[i]>a[j]) dp[i] = max(dp[i], 1+dp[j]);
			if(dp[i]>len) len = dp[i]; // storing len of max IS found so far
			//  for any i go to   0 <----------j <- i , and keep comparing
			//  if u can add i th element to any of the LIS computed     
		}
	}
	return len;
}
//2> O(n.logn) binary search approach
int binarysearch(vector<int> v,int l,int r, int x){
    while(l<r){
        int mid = (l+r)/2;
        if(v[mid]>=x){ r=mid; }
        else { l=mid+1; }
    }
    return r;
    
}
//----------------------------------------------------------------------
int longestSubsequence(int n, int a[])
{
   // your code here
	vector<int> tail;
	tail.push_back(a[0]);
	int len =1;
	for(int i=1;i<n;i++){
		if(a[i]>tail[len-1]){
		    tail.push_back(a[i]); len++;
		}
		else{
		    int ciel_ind = binarysearch(tail,0,len-1,a[i]);
		    tail[ciel_ind] = a[i];
		}
	}
	return len;
}
int main(){
	FAST_IO
	int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    };
}
