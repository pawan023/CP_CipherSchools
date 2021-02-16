
// Kth smallest element in Matrix

/*

Input:
N = 4
mat[][] =     	  {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.

Input:
N = 4
mat[][] =     	  {{10, 20, 30, 40}
                   {15, 25, 35, 45}
                   {24, 29, 37, 48}
                   {32, 33, 39, 50}}
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.

*/

#include <bits/stdc++.h> 
using namespace std;

int kthSmallest(const vector<vector<int>>& mat, int k) {
	int r=mat.size(), c=mat[0].size();
	priority_queue<int,vector<int>,greater<int>> pq;
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			pq.push(mat[i][j]);
		}
	}
	
	int kth;
	while(k--){
		kth=pq.top();
		pq.pop();
	}
	
	return kth;
}

int main() {	
	int m,n,k; 
	cin>>m>>n;
	vector<vector<int>> mat;
	for(int i=0; i<m; i++){
		vector<int> v;
		for(int j=0; j<n; j++){
			int x; cin>>x;
			v.push_back(x);
		}
		mat.push_back(v);
	}
	cin>>k;
	cout<<kthSmallest(mat,k)<<endl;
	return 0;
}
/*
input
4 4
12 2 3 34
15 63 7 82
91 10 11 12
113 134 5 16
8

output
12
*/


