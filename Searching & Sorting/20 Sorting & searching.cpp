#include<iostream>
using namespace std;

// Binary search
// time:O(logN), space:O(1) iterative
int binSearch(int arr[], int n, int x){
	int low=0, high=n-1;
	while(low<=high){
		int mid=(high+low)/2;
		if(x==arr[mid]) return mid;
		else if(x<arr[mid]) high=mid-1;
		else low=mid+1;
	}
	return -1;
}
// time:O(logN), space:O(logN) recurisve
int binSearch(int arr[], int low, int high, int x){
	if(low>high) return -1;
	int mid=(high+low)/2;
	if(x==arr[mid]) return mid;
	else if(x<arr[mid]) return binSearch(arr,low,mid-1,x);
	else return binSearch(arr,mid+1,high,x);
}
//--------------------------------------------------------------------------
// MERGE sort
#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int h){
	int n1=(m-l)+1, n2=h-m;
	int left[n1], right[n2];
	
	for(int i=0; i<n1; i++){
		left[i] = arr[l+i];
	}
	for(int i=0; i<n2; i++){
		right[i] = arr[m+1+i];
	}
	
	int i=0, j=0, k=l; // K=L not 0
	while(i<n1&&j<n2){
		if(left[i]<=right[j]) // = provides stability
			arr[k++]=left[i++];
		else
			arr[k++]=right[j++];
	}
	while(i<n1) arr[k++]=left[i++];
	while(j<n2) arr[k++]=right[j++];
}

void mergeSort(int arr[], int l, int h){
	if(h>l){ // at least 2 elements r present
		int m = l+((h-l)/2); // = (r+l)/2, but this may lead to overflow for high values
		mergeSort(arr,l,m); // divide arr in 2 halves left &
		mergeSort(arr,m+1,h); // right
		merge(arr,l,m,h); // merging above 2 halves
	}
}

int main(){
	int arr[] = {-1,8,0,2,-3,7,6,0,4};
	//int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = 9;
	mergeSort(arr,0,n-1);
	for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}
//-------------------------------------------------------------------------------
// Quick sort
// QuickSort using Lomuto Partition

#include<bits/stdc++.h>
using namespace std;
// Lomuto Partition
// assumption pivot is always the last item
// anyways it can also handle any random item as pivot
int Lpartition(int arr[], int l, int h){
	// swap(arr[p],arr[h]), in case pivot isnt last item
	int pivot = arr[h];
	int i = l-1;
	for(int j=l; j<=h-1; j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[h]);
	return (i+1); //new indx of pivot
	// all elements [l...i] < [i+1] > all [i+2...h]
}

void qSort(int arr[], int l, int h){
	if(h>l){
		int p = Lpartition(arr,l,h);
		qSort(arr,l,p-1);
		qSort(arr,p+1,h);
	}
}

