// Search an element in a sorted and rotated array

#include<iostream>
using namespace std;

// 1> Search in a sorted rotated Array
// ascending order & left rotated
// time:O(log(N)), space:O(1)

int search(int arr[], int n, int x){
	int low=0, high=n-1;
	while(low<=high){
		int mid=(high+low)/2;
		if(arr[mid]==x) return mid;
		//check for sorted half
		if(arr[low]<arr[mid]){ // left half is sorted
			if(x>=arr[low]&&x<arr[mid]) // item is present in left half
				high = mid-1;
			else
				low = mid+1;
		}
		else{ // right half is sorted
			if(x>arr[mid]&&x<=arr[high]) // item is present in right half
				low = mid+1;
			else
				high = mid-1;
		}
	}
	return -1;
}

//-----------------------------------------------------------------------------

int main(){
	int arr[] = {2,3,4,5,6,7,8,9};
	int n=8;
	cout<<search(arr,8,9);
}




