//------------------------------------------------------------------------------------
// Find a peak element
// Given an array of integers. Find a peak element in it. 
// An array element is a peak if it is NOT smaller than its neighbours. For corner elements, we need to consider only one neighbour. 
//------------------------------------------------------------------------------------
/*
Input: array[]= {5, 10, 20, 15}
Output: 20
The element 20 has neighbours 10 and 15,
both of them are less than 20.

Input: array[] = {10, 20, 15, 2, 23, 90, 67}
Output: 20 or 90
The element 20 has neighbours 10 and 15, 
both of them are less than 20, similarly 90 has neighbous 23 and 67.

Following corner cases give better idea about the problem. 

If input array is sorted in strictly increasing order, the last element is always a peak element. 
For example, 50 is peak element in {10, 20, 30, 40, 50}.
If the input array is sorted in strictly decreasing order, the first element is always a peak element. 
100 is the peak element in {100, 80, 60, 50, 20}.
If all elements of input array are same, every element is a peak element.
*/
//------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define mod 1000000007
#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

//------------------------------------------------------------------------------------
// NAIVE
// 1> find peak element (  a[i-1]<=a[i]>=a[i+1] )
// every independent array do have a peak element
// time:O(N), space:O(1)
int peakElement(int arr[], int n){
	if(n==1 or arr[0]>=arr[1]) return arr[0];
	if(arr[n-1]>=arr[n-2]) return arr[n-1];
	for(int i=1; i<n-1; i++){
		if(arr[i-1]<=arr[i] && arr[i+1]<=arr[i]) return arr[i];
	}
}

//------------------------------------------------------------------------------------

// 2> EFFICIENT
// time:O(log(N)), space:O(1)
int peakElement(int arr[], int n){
	int low=0, high=n-1;
	while(low<=high){
		int mid=(high+low)/2;
		if( (mid==0 or arr[mid-1]<=arr[mid]) && (mid==n-1 or arr[mid+1]<=arr[mid]) ) return arr[mid];
		// if we ignore right arr that dosent mean right arr dont have peak ele.
		// right may or may not have. But we can surely say left do have.
		else if(mid>0 && arr[mid-1]>=arr[mid])
			high = mid-1;
		else
			low = mid+1;	
	}
	return -1; // will nvr happen
}

//------------------------------------------------------------------------------------

// Driver code
int main(){
    FAST_IO
    int arr[] = { 1, 3, 20, 4, 1, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << peakElement(arr, n);
    return 0;
}

