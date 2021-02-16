//------------------------------------------------------------------------------------
// K’th Smallest Element in Unsorted Array
//------------------------------------------------------------------------------------
/*
Given an array and a number k where k is smaller than size of array, 
we need to find the k’th smallest element in the given array. It is given that all array elements are distinct.

Input: arr[] = {7, 10, 4, 3, 20, 15} 
k = 3 
Output: 7

Input: arr[] = {7, 10, 4, 3, 20, 15} 
k = 4 
Output: 10 
*/
//------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define mod 1000000007
#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

//------------------------------------------------------------------------------------
// Naive: time:O(NLogn) 
// sort the given array using a O(N log N) return the element at index k-1 in the sorted array. 

// EFFICIENT
// time:O(N) avg, O(N^2) worst case, space:O(1)

int Lpartition(int arr[], int l, int h){
	int pivot = arr[h];
	int i = l-1;
	for(int j=l; j<=h-1; j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[h]);
	return (i+1);
}

int KthSmallest(int arr[], int n, int k){
	int l=0, h=n-1;
	while(l<=h){
		int p = Lpartition(arr,l,h);
		if(p==k-1) return p; // return index, if found
		else if(p>k-1) h=p-1;
		else l=p+1;
	}
	return -1; // return -1, if not found
}

//------------------------------------------------------------------------------------

// Driver code
int main(){
	int arr[] = {-1,7,2,4,6,7,8,3};
	int ind = KthSmallest(arr,8,5);
	int ans = ind<0 ? -1 : arr[ind];
	cout<<ans;
}


