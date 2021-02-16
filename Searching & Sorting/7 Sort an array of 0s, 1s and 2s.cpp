//------------------------------------------------------------------------------------
// Sort an array of 0s, 1s and 2s
//------------------------------------------------------------------------------------
/*
Input: {0, 1, 2, 0, 1, 2}
Output: {0, 0, 1, 1, 2, 2}

Input: {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}
Output: {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}
*/
//------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define mod 1000000007
#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

//------------------------------------------------------------------------------------
// Naive: O(N) simply find freq of each item.
// Then store all the 0s in the beginning followed by all the 1s then all the 2s.

// 1> EFFICIENT
// Dutch National Flag Algorithm OR 3-way Partitioning:
// time:O(N), space:O(1)

void sort012(int arr[], int n){ 
    	int low=0, high=n-1;
	int mid=0;
	while(mid<=high){
		if(arr[mid]==0) swap(arr[low++],arr[mid++]);
		else if(arr[mid]==1) mid++;
		else swap(arr[mid],arr[high--]);
	} 
} 

//------------------------------------------------------------------------------------

// Driver code
int main(){
    FAST_IO
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    sort012(arr, n); 
    cout << "array after segregation "; 
    for (int i=0; i<n; i++) cout<<arr[i]<<" "; 
    return 0; 
}

