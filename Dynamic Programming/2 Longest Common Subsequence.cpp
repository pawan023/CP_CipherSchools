// Longest Common Subsequence

#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
#define Max 100001
using namespace std;
/*
LCS variations: len of lcs, l=lcs
1> diff utility, delete f1-l and f2-l is the differnce in first and second file
2> min no of del&insertion to make convert str1 to str2 , m-l deletion & n-l insertion
3> shortest common supersequence, (ans = s1+s2-l)
4> longest palindromic subseq , find(lcs(s1,reverse(s1))
5> longest repeating subseq
	// 
	if(s1[x-1]==s2[y-1] && x-1!=y-1){//char match, so both string reduced by 1 length
        return 1 + lcs(x-1,y-1,s1,s2);
    }
    else{//char dont match
        // a> we reduce s1 by 1 len, and calculate lcs
        // b> similarly s2 by 1, and return max(of  the lcs(a), lcs(b) )
        return max(lcs(x-1,y,s1,s2), lcs(x,y-1,s1,s2));
    }
    //
6> printing lCS
	// start from bottom right index: 
		if s1[i-1]==s2[j-1] print that char and go diagonally \ up 
		else go to max(dp[i][j-1] , dp[i-1][j]) i.e either <-- or  ^
		
		since u r traversing from end , so append char at front always
	//
7> space improved lcs, done below
*/
//1>
//recursive O(2^x)
int lcs(int x, int y, string s1, string s2){
    //base cases
    // two empty strings have nothing to compare, common=0
    // also if any one of string is emnpty, nothing is common =0
    if(x==0 or y==0) return 0;
    //recursive calls
    if(s1[x-1]==s2[y-1]){//char match, so both string reduced by 1 length
        return 1 + lcs(x-1,y-1,s1,s2);
    }
    else{//char dont match
        // a> we reduce s1 by 1 len, and calculate lcs
        // b> similarly s2 by 1, and return max(of  the lcs(a), lcs(b) )
        return max(lcs(x-1,y,s1,s2), lcs(x,y-1,s1,s2));
    }
}
//2>
// dp //O(xy)space and O(xy)time
int lcs(int x, int y, string s1, string s2){
    
    int dp[x+1][y+1] = {};
    // base case, make first row and col = 0;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(s1[i-1]==s2[j-1]) { dp[i][j] = 1 + dp[i-1][j-1]; } 
            else { dp[i][j] = max(dp[i-1][j], dp[i][j-1]);  }   
        }
    }
    return dp[x][y];
}
//3>dp space improved
//O(2y) space
int lcs(int x, int y, string s1, string s2){
	//since at any instant we only require current row and pev row data
    int dp[2][y+1] ;
    int fake;
    for(int i=0 ;i<=x; i++){
    	fake = i%2==0 ? 0 : 1; //fake = i&1;
    	// for odd rows, fake=1 and for evem fake=0
    	// for odd i we store in row 1, and use row 0 data
    	// for even row we store in row 0, and use row 1 data
        for(int j=0; j<=y; j++){
        	if(i==0 or j==0) dp[fake][j] = 0;
            else if(s1[i-1]==s2[j-1]) { dp[fake][j] = 1 + dp[1-fake][j-1]; } 
            else { dp[fake][j] = max(dp[1-fake][j], dp[fake][j-1]);  }
        }
    }
    return dp[fake][y];
}
//4> O(y) space
int lcs(int x, int y, string s1, string s2){
	//since at any instant we only require current row and pev row data
    int dp[y+1] = {} ;
    for(int i=1 ;i<=x; i++){
        int prev=dp[0];
        for(int j=1; j<=y; j++){
        	int top = dp[j];
            if(s1[i-1]==s2[j-1]) { dp[j] = 1 + prev; } 
            else { dp[j] = max(dp[j], dp[j-1]);  }
            prev = top;
        }
    }
    return dp[y];
}
//5> lcs  with  string  and len
int lcs(int x, int y, string s1, string s2){
    
    int dp[x+1][y+1] = {};
    // base case, make first row and col = 0;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(s1[i-1]==s2[j-1]) { dp[i][j] = 1 + dp[i-1][j-1]; } 
            else { dp[i][j] = max(dp[i-1][j], dp[i][j-1]);  }   
        }
    }
    // finding lcs string
    string s;
    for(int i=x,j=y;i>=0 && j>=0;){
    	//since u r traversing from end , so append char at front always
        if(s1[i-1]==s2[j-1]){ 
			s = s1[i-1]+s;  i--, j--; //moving to diag 
		} 
        else { 
			if(dp[i-1][j] > dp[i][j-1]) i--; // moving to top ^
			else j--; // moving to left <--
		}   
    }
    cout<<s<<endl;
    return dp[x][y];
}

int main()
{
    int t,n,k,x,y;
    
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    return 0;
}
