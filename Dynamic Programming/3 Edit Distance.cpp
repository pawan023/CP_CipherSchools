// Edit Distance

#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
#define Max 100001
using namespace std;
//1> recursive 3^n
int ED(string s, string t, int l1, int l2){
			// two empty string are similar, so 0 operations needed
			//base cases
            //if(l1==0 and l2==0) return 0;  //this case can be handled by below case
            // to make a non mepty string == empty or vice versa
            // either u  del all existing char or add all requied char
            // i.e.  l operations
		    if(l1==0) return l2;
		    else if(l2==0) return l1;
		    //recursive calls
		    // if curr chars are equal simply call for rest lefted string
		    if(s[l1-1]==t[l2-1]) {
		        return ED( s,t,l1-1,l2-1 );
		    }
		    // if thy are unequal, u have 3 choices to make
		    // since u do any 1 of these three, i.e 1 operation
		    // therefore u return 1 + min(a,d,r)
		    // add = del a char from t
		    // del = del a char from s
		    //replace = skipping a char from both s & t (if equal)
		    			//else replacing s char with t char
		    else{
		        int add = ED( s,t,l1,l2-1 );
		        int del = ED( s,t,l1-1,l2 );
		        int replace = ED( s,t,l1-1,l2-1 );
		        return 1+min(add,min(del,replace));
		    }
	}
//2>
// dp //O(s*t)space and O(s*t)time
int editDistance(string s, string t){
		    int l1=s.size(), l2=t.size();
		    int dp[l1+1][l2+1];
		    for(int i=0;i<=l1;i++){
		        for(int j=0;j<=l2;j++){
		            //base cases
		            if(i==0) dp[i][j]= j;
		            else if(j==0) dp[i][j]= i;
		            // recursive calls
		            else if(s[i-1]==t[j-1]){
		                dp[i][j] = dp[i-1][j-1];
		            }
		            else{
		                dp[i][j] = 1+ min( dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]) );
		            }
		        }
		    }
		    return dp[l1][l2];
		    
}
//3>dp space improved
/*
dp[i-1][j-1],  dp[i-1][j]
dp[i][j-1],    dp[i][j]
The corresponding code:
dp[i][j] = min(dp[i - 1][j - 1] , dp[i][j - 1] , dp[i - 1][j] ) + 1

When using 1d array. We are updating cur[ ] from beginning to the end again and again (Row of 2D array times). The relative position is like this:

pre,       cur[i]
cur[i-1]   cur[i](waiting for the update) 
*/

int editDistance(string s, string t){
		    int l1=s.size(), l2=t.size(), prev;
		    
		    int dp[l2+1];
		    for(int j=0;j<=l2;j++){ dp[j] = j; }
		    
		    for(int i=1;i<=l1;i++){
		        prev = dp[0],//to hold diag value
		        dp[0]=i; // since base case for each i = i;
		        for(int j=1;j<=l2;j++){
		            //base cases
		            int temp = dp[j];
		            // recursive calls
		            if(s[i-1]==t[j-1]){
		                dp[j] = prev;
		            }
		            else{
		                dp[j] = 1+ min( prev ,min(dp[j-1], dp[j]) );
		            }
		            prev = temp;
		        }
		    }
		    return dp[l2];
}
int main(){
	FAST_IO
	int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	int ans = editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}
