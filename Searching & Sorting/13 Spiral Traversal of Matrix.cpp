
// Spiral Traversal of Matrix
// O(n^2) time O(1) space

/*

input:
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

input:
3 3
1 2 3
4 5 6
7 8 9
output:
1 2 3 6 9 8 7 4 5

//edge case
input:
1 4
1 2 3 4
output:
1 2 3 4

//edge case
input:
4 1
1
2
3
4
output:
1 2 3 4

*/

#include <bits/stdc++.h> 
using namespace std;

void printSpiral(vector<vector<int>> &arr){
	int m=arr.size(), n=arr[0].size();
	int top=0, left=0, right=n-1, bottom=m-1;
	
	while(top<=bottom && left<=right){
		for(int i=left; i<=right; i++)
			cout<<arr[top][i]<<" ";
		top++;
		
		for(int i=top; i<=bottom; i++)
			cout<<arr[i][right]<<" ";
		right--;
		
		if(top<=bottom){
			for(int i=right; i>=left; i--)
				cout<<arr[bottom][i]<<" ";
			bottom--;
		}
		
		if(left<=right){
			for(int i=bottom; i>=top; i--)
				cout<<arr[i][left]<<" ";
			left++;
		}
	}
}

int main() {	
	int m,n; cin>>m>>n;
	vector<vector<int>> arr;
	for(int i=0; i<m; i++){
		vector<int> v;
		for(int j=0; j<n; j++){
			int x; cin>>x;
			v.push_back(x);
		}
		arr.push_back(v);
	}
	printSpiral(arr);
	return 0;
}


