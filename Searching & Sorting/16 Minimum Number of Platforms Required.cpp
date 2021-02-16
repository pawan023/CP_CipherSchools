#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
#define Max 1000000007
using namespace std;

//  Minimum Platforms Required
// Given arrival and departure times of all trains that reach a railway station, 
// the task is to find the minimum number of platforms required for the railway 
// station so that no train waits.

/*
Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}
dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
Output: 3
Explantion: There are at-most three trains at a time (time between 11:00 to 11:20)

Input: arr[] = {9:00, 9:40}
dep[] = {9:10, 12:00}
Output: 1
Explantion: Only one platform is needed.

*/
//---------------------------------------------------------


// 1> Naive Solution:
// Time Complexity: O(n^2)  Space Complexity: O(1)
/*
Approach: The idea is to take every interval one by one and find the number 
of intervals that overlap with it. Keep track of the maximum number of intervals 
that overlap with an interval. Finally, return the maximum value.
*/
int findPlatform(int arr[], int dep[], int n){ 
  
    int platform=0,i=0,j=0,p=0; 
    // run a nested  loop to find overlap 
    for (int i = 0; i < n; i++) { 
        // minimum platform 
        p=1; 
        for (int j = i+1; j < n; j++) { 
            // check for overlap 
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||  (arr[j] >= arr[i] && arr[j] <= dep[i])) 
                p++; 
        } 
        platform = max(platform,p); 
    } 
    return result; 
} 
//---------------------------------------------------------

//---------------------------------------------------------
// 2> Efficient Solution:
/*
arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}

All events are sorted by time.
Total platforms at any time can be obtained by
subtracting total departures from total arrivals
by that time.

 Time      Event Type     Total Platforms Needed 
                               at this Time                               
 9:00       Arrival                  1
 9:10       Departure                0
 9:40       Arrival                  1
 9:50       Arrival                  2
 11:00      Arrival                  3 
 11:20      Departure                2
 11:30      Departure                1
 12:00      Departure                0
 15:00      Arrival                  1
 18:00      Arrival                  2 
 19:00      Departure                1
 20:00      Departure                0

Minimum Platforms needed on railway station 
= Maximum platforms needed at any time 
= 3 

// Time Complexity : O(n) Auxiliary Space : O(1)
*/
int findPlatform(int arr[], int dep[], int n){ 
    // Sort arrival and departure arrays 
    sort(arr, arr + n); 
    sort(dep, dep + n); 
  
    int platform=0,i=0,j=0,p=0; 
  
    while(i<n && j<n){
	        if(arr[i]<=dep[j]){
	            p++;
	            i++;
	        }
	        else{
	            p--;
	            j++;
	        }
	        platform = max(p,platform);
	    } 
  
    return platform; 
}
//---------------------------------------------------------
//---------------------------------------------------------
int main() {
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n); 
    return 0;
}
//---------------------------------------------------------
