//------------------------------------------------------------------------------------
// Find first and last positions of an element in a sorted array 
//------------------------------------------------------------------------------------
/*
Given a sorted array with possibly duplicate elements, the task is to 
find indexes of first and last occurrences of an element x in the given array.

Input : arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125}    
        x = 5
Output : First Occurrence = 2
         Last Occurrence = 5

Input : arr[] = {1, 3, 5, 5, 5, 5, 7, 123, 125 }    
        x = 7
Output : First Occurrence = 6
         Last Occurrence = 6
*/
//------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define mod 1000000007
#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

//------------------------------------------------------------------------------------
// NAIVE
// time:O(N), space:O(1)

void findFirstAndLast(int arr[], int n, int key){
    int first = -1, last = -1;
    for(int i=0; i<n; i++){
    	if(arr[i]!=key) continue;
    	if(first==-1) first=i;
    	last = i;
	}
    if(first==-1) cout<<"absent"<<"\n";
    else cout<<first<<" "<<last<<"\n";
}

//------------------------------------------------------------------------------------

// 2> EFFICIENT
// time:O(logN), space:O(1)
/*
// we have a rectangular matrix having 4 corners. a simple observation is we can fasten our search
// by starting either from top right cell OR bottom left cell
// lets say we start from top right, 
	now if curr_ele==key, return location.
	else if curr_ele<key, =>> our element for sure is not present in that column, i.e we can move left <--
	else if curr_ele>key, =>> our element for sure is not present in that row, i.e we can move down 
*/

void findFirstAndLast(int arr[], int n, int key){
    int first = -1, last = -1;
    //finding first occurence
    int low=0, high=n-1, mid;
    while(low<=high){
    	mid=low+(high-low)/2;
    	if(arr[mid]>key) high=mid-1;
    	else if(arr[mid]<key) low=mid+1;
    	else{
    		if(mid==0 or arr[mid-1]<arr[mid]){
    			first=mid;
			break;
		}
		else high=mid-1;
		}
	}
	//finding last occurence
	low=0, high=n-1;
    while(low<=high){
    	mid=low+(high-low)/2;
    	if(arr[mid]>key) high=mid-1;
    	else if(arr[mid]<key) low=mid+1;
    	else{
    		if(mid==n-1 or arr[mid+1]>arr[mid]){
    			last=mid;
			break;
		}
		else low=mid+1;
		}
	}
    cout<<first<<" "<<last<<"\n";
    return;
}

//------------------------------------------------------------------------------------

// Driver code
int main(){
    FAST_IO
    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(int);
    int key; cin>>key;
    findFirstAndLast(arr, n, key);
    return 0;
}

