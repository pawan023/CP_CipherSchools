//------------------------------------------------------------------------------------
// Segregate 0s and 1s in an array 
//------------------------------------------------------------------------------------
/*
Input array   =  [0, 1, 0, 1, 0, 0, 1, 1, 1, 0] 
Output array =  [0, 0, 0, 0, 0, 1, 1, 1, 1, 1] 
*/
//------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define mod 1000000007
#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

//------------------------------------------------------------------------------------
// Naive: O(N) simply count no of zero's. Then fill the array with that many zeros and rest with ones

// 1> EFFICIENT
// time:O(N), space:O(1)

void segregate0and1(int arr[], int size) {
	int zero=0, one=size-1;
	while(zero<one){
		if(arr[zero]==1) swap(arr[zero],arr[one--]);
		else zero++;
	}
}

//------------------------------------------------------------------------------------

// Driver code
int main(){
    FAST_IO
    int arr[] = {0, 1, 0, 1, 1, 1};\
    int size = sizeof(arr)/sizeof(arr[0]);
    segregate0and1(arr,size);
    cout<<"Array after segregation is "; 
    for (int i=0; i<size; i++) cout<<arr[i]<<" "; 
    return 0;
}

