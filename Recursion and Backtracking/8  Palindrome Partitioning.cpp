#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
#define Max 1000000007
using namespace std;

// Palindromic patitioning
// Given a string str, a partitioning of the string is a palindrome partitioning 
// if every sub-string of the partition is a palindrome. 
// Determine the fewest cuts needed for palindrome partitioning of given string. 
/*
Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
*/

//1> recursion, exponential time
	bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int palP(string s, int i, int j){
        if(isPalindrome(s,i,j)) return 0; //no Partition needed if already a palindrome
        int res = INT_MAX;
        for(int k=i; k<j; k++){
            res = min(res, 1+palP(s,i,k)+palP(s,k+1,j));
        }
        return res;
    }
    int palindromicPartition(string str){
        return palP(str,0,str.size()-1);
    }

//2> dp O(n^3) time and O(n^2) space
// the ispalindrome() can be optimised by taking another 2d array, but still O(n^3)
	bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    
    int palindromicPartition(string str){
        int n = str.size();
    	int dp[n][n] = {};
    	// since j>=i, all elements below diagnonal will not be filled/used
    	// base case cell[i][i] = 0, i.e a single char is a palindrome 
    	// we fill matrix diagonally and our ans is on dp[0][n-1]
    	for(int gap = 1; gap<n; gap++){
    		for(int i=0; i+gap<n; i++){
    			int j=i+gap;
    			if(isPalindrome(str,i,j)) dp[i][j] = 0;
    			else{
    			    dp[i][j] = INT_MAX;
    			    for(int k=i; k<=j-1; k++){
    				    dp[i][j] = min( dp[i][j], 1+dp[i][k]+ dp[k+1][j]);
    			    }
    			}
    		}
    	}
    	return dp[0][n-1];
    }
//----------------------
int main() 
{ 
	    string s = "geek";
    	
    	cout<<palindromePartition(s);
    	
    	return 0;;
	
}
