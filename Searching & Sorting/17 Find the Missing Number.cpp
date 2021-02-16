#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
#define Max 1000000007
using namespace std;

//  Find the Missing Number

/*
You are given a list of n-1 integers and these integers are in the range of 1 to n. 
There are no duplicates in the list. One of the integers is missing in the list. 
Write an efficient code to find the missing integer.

Input: arr[] = {1, 2, 4, 6, 3, 7, 8}
Output: 5
Explanation: The missing number from 1 to 8 is 5

Input: arr[] = {1, 2, 3, 5}
Output: 4
Explanation: The missing number from 1 to 5 is 4

x^0 = x
x^x = 0
x^y = y^x  //commutative 
x^(y^z) = (x^y)^z = y^(z^x)  //associative

*/
//---------------------------------------------------------

// 1> time: O(N) space: O(1)
// using sum of n numbers formula, and handling overflow with a clever implementation
// N = no of items in arr

//---------------------------------------------------------

int getMissingNo(int arr[], int n){ 
    int sum=1, j=2; 
    for(int i=0; i<n; i++, j++){
        sum += j;
        sum -= arr[i];
    }
    return sum; 
} 

//---------------------------------------------------------
// 2> Efficient Solution: 
// time: O(N) space: O(1)

int getMissingNo(int arr[], int n){ 
    int exor=1, j=2; 
    for(int i=0; i<n; i++){
        exor = exor^j;
        exor = exor^arr[i];
    }
    return exor; 
} 

//---------------------------------------------------------
int main() {
	int arr[] = {1, 2, 3, 5};
    	cout<<getMissingNo(arr,sizeof(arr)/sizeof(arr[0]));
    	return 0;
}
//---------------------------------------------------------
