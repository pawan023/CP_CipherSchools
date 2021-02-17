// Combinations
//---------------------------------------------------------------------
/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

You may return the answer in any order.

 
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Input: n = 1, k = 1
Output: [[1]]

*/
//---------------------------------------------------------------------
//recursive

class Solution {
	private:
	vector<vector<int>> res;
public:
	void dfs(int k, int n, int idx, vector<int> path){
		if(k==0){
			res.push_back(path);
		}
		else{
			for(int i=idx+1;i<=n;i++){
				path.push_back(i);
				dfs(k-1,n,i,path);
				path.pop_back();
			}
		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<int> path;
		dfs(k,n,0,path);
		return res;
	}
};
//---------------------------------------------------------------------
//iterative

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
	}
};
//---------------------------------------------------------------------

