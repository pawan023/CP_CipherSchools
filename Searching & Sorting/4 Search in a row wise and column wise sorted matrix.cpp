//------------------------------------------------------------------------------------
// Search in a row wise and column wise sorted matrix 
//------------------------------------------------------------------------------------
/*
Input: mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
              x = 29
Output: Found at (2, 1)
Explanation: Element at (2,1) is 29

Input : mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
              x = 100
Output : Element not found
Explanation: Element 100 is not found
*/
//------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define mod 1000000007
#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

//------------------------------------------------------------------------------------
// NAIVE
// time:O(MN), space:O(1)
/*
traverse the matrix, as u encounter any cell: compare if its == key. if yes return its coordinates.
if no match found after full traversal return false;
*/

//------------------------------------------------------------------------------------

// 2> EFFICIENT
// time:O(N+M), space:O(1)
/*
// we have a rectangular matrix having 4 corners. a simple observation is we can fasten our search
// by starting either from top right cell OR bottom left cell
// lets say we start from top right, 
	now if curr_ele==key, return location.
	else if curr_ele<key, =>> our element for sure is not present in that column, i.e we can move left <--
	else if curr_ele>key, =>> our element for sure is not present in that row, i.e we can move down 
*/

void search(const vector<vector<int>>& mat, int key){ //m*n
    int m = mat.size(), n = mat[0].size();
    int i=0, j=n-1; //top right cell
    bool found=false;
    while(i<m && j>=0){
    	if(mat[i][j]<key) i++; // we need larger element so move down
    	else if(mat[i][j]>key) j--; // we need smaller element so move left
    	else { 
		cout<<i<<" "<<j<<"\n"; // key found
		found=true;
		break;
	}
    }
    if(!found) cout<<"Absent"<<"\n";
}

//------------------------------------------------------------------------------------

// Driver code
int main(){
    FAST_IO
    vector<vector<int>> mat = { { 10, 20, 30, 40 },
			        { 15, 25, 35, 45 },
			        { 27, 29, 37, 48 },
			        { 32, 33, 39, 50 } };
   
    int key;
    cin>>key;		                    
    search(mat, key);
    return 0;
}

