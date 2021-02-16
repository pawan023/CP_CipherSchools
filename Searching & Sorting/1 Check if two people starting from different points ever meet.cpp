//------------------------------------------------------------------------------------
// Check if two people starting from different points ever meet
//------------------------------------------------------------------------------------
/*
There are two people that start from two different positions, 
let’s say x1 and x2. Both can jump v1 and v2 meters ahead respectively. 
We have to find if both will ever meet given that the number of jumps taken by both has to be same.

Input  : x1 = 5, v1 = 8, x2 = 4, v2 = 7
Output : No
Explanation: The first person is starting ahead of the second one.
and his speed is also greater than the second one, so they will never meet.

Input  : x1 = 6, v1 = 6, x2 = 4, v2 = 8
Output : Yes
*/
//------------------------------------------------------------------------------------
             
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define mod 1000000007
#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

//------------------------------------------------------------------------------------
// NAIVE
// time: O(N) space: O(1)
bool everMeet(int x1, int x2, int v1, int v2) { 
    if(x1<x2 && v1<=v2) return 0; // x1 can never overtake x2
	if(x2<x1 && v2<=v1) return 0; // x2 can never overtake x1
	// making x1 greater
	if(x1<x2)
		swap(x1,x2), swap(v1,v2);       
     
    while(x1>x2) {  
        x1 += v1;
        x2 += v2;
        if(x1==x2) break;
    } 
    return x1==x2;    
}
//------------------------------------------------------------------------------------

// EFFICIENT
// time: O(1) space: O(1)
bool everMeet(int x1, int x2, int v1, int v2){
	if(x1<x2 && v1<=v2) return 0; // x1 can never overtake x2
	if(x2<x1 && v2<=v1) return 0; // x2 can never overtake x1
	if(x1<x2)
		swap(x1,x2), swap(v1,v2);
	// x1-x2 = jumps(v2-v1) , since jumps=int => (x1-x2)is a multiple of(v2-v1).
	return ( (x1-x2)%(v2-v1) == 0 );
}

//------------------------------------------------------------------------------------

// Driver code
int main(){
    FAST_IO
    cout<<everMeet(5,4,8,7)<<"\n"; // No
    cout<<everMeet(6,4,6,8)<<"\n"; // yes    
}


