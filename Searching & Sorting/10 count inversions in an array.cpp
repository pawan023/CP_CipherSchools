//------------------------------------------------------------------------------------
// count inversions in an array
//------------------------------------------------------------------------------------
/*
Inversion Count for an array indicates – how far (or close) the array is from being sorted.
If array is already sorted then inversion count is 0. If array is sorted in reverse order 
that inversion count is the maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 
Input: arr[] = {8, 4, 2, 1}
Output: 6

Explanation: Given array has six inversions:
(8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).


Input: arr[] = {3, 1, 2}
Output: 2

Explanation: Given array has two inversions:
(3, 1), (3, 2) 
*/
//------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define mod 1000000007
#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

//------------------------------------------------------------------------------------
// naive O(N^2) time & O(1) space
int countInversions(int arr[], int n){
    int res=0;
    for(int i=0;i<(n-1);i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])
                res++;
        }
    }
    return res;
}
//------------------------------------------------------------------------------------
// efficient time: O(nlogn) space: O(1)
int countAndMerge(int arr[], int l, int m, int h){
	int n1=m-l+1, n2=h-m;
	int left[n1], right[n2];
	for(int i=0; i<n1; i++){
		left[i] = arr[l+i];
	}
	for(int i=0; i<n2; i++){
		right[i] = arr[m+1+i];
	}
	int i=0, j=0, k=l, res=0;
	while(i<n1 && j<n2){
		if(left[i]<=right[j]) { arr[k++] = left[i++]; }
		else {
			arr[k++] = right[j++]; res += (n1-i);
		}
	}
	while(i<n1) arr[k++] = left[i++];
	while(j<n2) arr[k++] = right[j++];
	
	return res;
}

int countInversions(int arr[], int l, int h){
	int res = 0;
	if(h>l){
		int m=l+(h-l)/2;
		res += countInversions(arr,l,m);
		res += countInversions(arr,m+1,h);
		res += countAndMerge(arr,l,m,h);
	}
	return res;
}
//------------------------------------------------------------------------------------

// Driver code
int main(){
	int arr[] = {2,4,1,3,5};
	cout<< countInversions(arr,0,4)<<"\n";
	for(int i=0; i<5; i++) cout<<arr[i]<<" ";

}


