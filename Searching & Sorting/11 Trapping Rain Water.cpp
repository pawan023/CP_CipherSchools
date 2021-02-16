// Trapping Rain Water

#include<bits/stdc++.h>
using namespace std;

/* // time: O(n^2) space: O(1)
int trappCap(int arr[], int n){
	if(n<3) return 0;
	int total=0;
	for(int i=0; i<n; i++){
		if(i==0 or i==n-1) continue;
		int lmax=arr[i], rmax=arr[i], j=i-1;
		while(j>=0){
			if(arr[j]>lmax) lmax=arr[j];
			j--;
		}
		j=i+1;
		while(j<n){
			if(arr[j]>rmax) rmax=arr[j];
			j++;
		}
		// to avoid negative valu of cc we took default val of lmax=arr[i
		int currCap = min(lmax,rmax)-arr[i];-
		total += currCap;
	}
	return total;
}
*/

// // time: O(n) space: O(n) precomputing lmax and rmax
int trappCap(int arr[], int n){
	//if(n<3) return 0;
	int total=0, lmax[n], rmax[n];
	lmax[0]=arr[0], rmax[n-1]=arr[n-1];
	
	for(int i=1; i<n; i++)
		lmax[i] = max(arr[i],lmax[i-1]);
	
	for(int i=n-2; i>=0; i--)
		rmax[i] = max(arr[i],rmax[i+1]);
	
	for(int i=1; i<n-1; i++)
		total += min(lmax[i],rmax[i])-arr[i];
	
	return total;
}


int main(){
	int arr[] = { 3,3,5,0,0,3,1,4 };
	int n=8;
	cout<<trappCap(arr,n);
}
