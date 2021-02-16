//------------------------------------------------------------------------------------
// Alternative Sorting
//------------------------------------------------------------------------------------
/*
Given an array of integers, print the array in such a way that the 
first element is first maximum and second element is first minimum and so on.

Input : arr[] = {7, 1, 2, 3, 4, 5, 6}
Output : 7 1 6 2 5 3 4

Input : arr[] = {1, 6, 9, 4, 3, 7, 8, 2}
Output : 9 1 8 2 7 3 6 4
*/
//------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define mod 1000000007
#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

//------------------------------------------------------------------------------------
// Naive: time:O(N^2) simply find max and min, print & delete it. do it till arr is empty 

// 1> EFFICIENT
// time:O(NLogN), space:O(1)

void alternateSort(int arr[], int n) {
	sort(arr, arr+n);
	int i=0, j=n-1;
	while(i<j){
		cout<<arr[j--]<<" "<<arr[i++]<<" ";
	}
	if(n%2) cout<<arr[i]<<"\n";
} 

//------------------------------------------------------------------------------------

// Driver code
int main(){
    FAST_IO
    int arr[] = {1, 12, 4, 6, 7, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    alternateSort(arr, n); 
    return 0; 
}

