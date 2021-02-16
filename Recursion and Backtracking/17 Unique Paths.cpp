//----------------------------------------------------------------------------------
// Unique Paths
//----------------------------------------------------------------------------------
/*
A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid.

How many possible unique paths are there?

Input: m = 3, n = 7
Output: 28

Input: m = 7, n = 3
Output: 28

Input: m = 3, n = 3
Output: 6

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10^9.

efficient approach:
For mxn grid, robot has to move exactly m-1 steps down and n-1 steps right and these can be done in any order.

For the eg., given in question, 3x7 matrix, robot needs to take 2+6 = 8 steps with 2 down and 6 right in any order. 
That is nothing but a permutation problem. Denote down as 'D' and right as 'R', following is one of the path :-

D R R R D R R R

We have to tell the total number of permutations of the above given word.
So, decrease both m & n by 1 and apply following formula:-

Total permutations = (m+n)! / (m! * n!)
*/
//----------------------------------------------------------------------------------

class Solution {
public:
        // 3> // O(mn) time & space O(n)
        int uniquePaths(int m, int n) {
          if(m==1 || n==1) return 1;
          m--, n--;
          //ans = fact(m+n)/(fact(m)*fact(n));
          if(m<n) swap(m,n);
          long long ans=1; int i,j;
          for(i=m+1,j=1;i<=m+n;i++,j++){
              ans = ans*i;
              ans = ans/j;
        }
        return ans;
        
        /*  // 2>// O(mn) time & space O(n)
        vector<int> row(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                row[j] = row[j] + row[j-1];
            }
        }
        return row[n-1];
        
        */
        /* // 1>// O(mn) time & space O(mn)
        int dp[m][n];
        vector<vector<int>> v(m, vector<int>(n));
        for(int i=0,j=0;i<m or j<n;i++,j++){
            if(j<n) v[0][j]=1;
            if(i<m) v[i][0]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                v[i][j] = v[i][j-1] + v[i-1][j];
            }
        }
        return v[m-1][n-1];
        */
    }
};

//----------------------------------------------------------------------------------
