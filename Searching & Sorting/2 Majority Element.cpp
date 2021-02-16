//------------------------------------------------------------------------------------
// Majority Element
// Write a function which takes an array and prints the majority element (if it exists), otherwise prints “No Majority Element”
//------------------------------------------------------------------------------------
/*
Majority Element”. A majority element in an array A[] of size n is an element
that appears more than n/2 times (and hence there is at most one such element).

Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
Output : 4
Explanation: The frequency of 4 is 5 which is greater
than the half of the size of the array size. 

Input : {3, 3, 4, 2, 4, 4, 2, 4}
Output : No Majority Element
Explanation: There is no element whose frequency is
greater than the half of the size of the array size.
*/
//------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define mod 1000000007
#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

//------------------------------------------------------------------------------------
// NAIVE
// time: O(N^2) space: O(1)
/*
traverse each item, for each item find its no. of occurences.
if at any moment no. of occurences > N/2 return that item.
if no such item return INT_MIN
*/
//------------------------------------------------------------------------------------

// NAIVE Improved using Hashing
// time: O(N) space: O(N)
/*
traverse each itemof array and add it to hash map, where key=arr[i], val=freq.
after inserting each time, check if (freq>n/2) : return arr[i].
at the end return INT_MIN (no majority element exist)
*/
//------------------------------------------------------------------------------------

// EFFICIENT, constant extra space:
/*
(Using Moore’s Voting Algorithm):  

Approach: This is a two-step process. 
1> The first step gives the element that maybe the majority element in the array. 
If there is a majority element in an array, then this step will definitely return majority element, 
otherwise, it will return candidate for majority element.

2> Check if the element obtained from the above step is majority element. 
This step is necessary as there might be no majority element.
 
Algorithm: 
1> Loop through each element and maintains a count of majority element, and a majority index.
2> If the next element is same then increment the count if the next element is not same then decrement the count.
3> if the count reaches 0 then changes the maj_index to the current element and set the count again to 1.
4> Now again traverse through the array and find the count of majority element found.
5> If the count is greater than half the size of the array, print the element
6> Else print that there is no majority element
*/

// time: O(N) space: O(1)
int findMajority(const vector<int> &arr){
	// phase 1: finding a candidate for majority element
	int n = arr.size(), res=0, count=1;
	for(int i=1; i<n; i++){
		if(arr[i]==arr[res]) count++;
		else count--;
		
		if(count==0) res=i, count=1;
	}
	
	// phase 2: verifying, only needed if majority doesnt exist
	count = 0;
	for(int i=0; i<n; i++){
		if(arr[i]==arr[res]) count++;
	}
		
	return (count<n/2)? INT_MIN: res;
}
//------------------------------------------------------------------------------------

// Driver code
int main(){
    FAST_IO
    vector<int> arr1 = { 1, 1, 2, 1, 3, 5, 1 };
    cout<<findMajority(arr1)<<"\n"; // 1
    
    vector<int> arr2 = { 1, 3, 3, 3, 2 };
    cout<<findMajority(arr2)<<"\n"; // 3
    
    vector<int> arr3 = { 1, 3, 3, 1, 2 };
    cout<<findMajority(arr3)<<"\n"; // -2147483648
    
    vector<int> arr4 = {2, 2, 2, 2, 5, 5, 2, 3, 3};
    cout<<findMajority(arr4)<<"\n"; // 2
}

