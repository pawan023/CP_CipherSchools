// Coin Exchange Problem
// Min no of coins needed

#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
#define Max 100001
using namespace std;
//1> recursive
long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value){
	if(v==0) return 0;
	int res = INT_MAX;
    int n = numberOfCoins, v = value;
	for(int i=0;i<n;i++){
		if(coins[i] <= value){
			int subres = minimumNumberOfCoins(coins, n, v-coins[i]);
			if(subres!=INT_MAX)
				res = min(res, 1+subres);	
		}
	}
	return res==INT_MAX ? -1 : res;
}
//2>
// dp //O(n*v)space and O(n*v)time
long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value){
    int n = numberOfCoins, v = value;
    // each cell represent min no of coins require to pay j value,
    // using coins from 1..i
    int dp[n+1][v+1] = {}; // 0 coins needed  to pay amount 0
    for(int i=1;i<=v;i++){ dp[0][i] = -1; } // not possible to pay amount 
    // with 0 money in hand, invalid case= -1
    for(int i=1; i<=n; i++){
        for(int j=1; j<=v; j++){
            // if coin is usable, coin <= value
            // and after using that coin, lefted amount ,(value-coin)
            // is it payable?
            if(coins[i-1]<=j && dp[i][j-coins[i-1]]!=-1){
                if(dp[i-1][j] != -1){
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
                }
                else{// curr coin + old coins
                    dp[i][j] = 1+dp[i][j-coins[i-1]];
                }
            }
            // coin is not uaed, so past value is curr value
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][v];
}
//3>dp space improved
//coin denominations o(v)space
long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value){
    int n = numberOfCoins, v = value;
    // each cell represent min no of coins require to pay j value,
    int dp[v+1] ; 
    fill(dp,dp+v+1,-1); // assume rest to be inavlid amount, non payable
    dp[0] = 0; // 0 coins needed  to pay amount 0
    for(int i=1; i<=n; i++){
        for(int j=1; j<=v; j++){
            // if coin is usable, coin <= value
            // and after using that coin, lefted amount ,(value-coin)
            // is it payable?
            if(coins[i-1]<=j && dp[j-coins[i-1]]!=-1){
                if(dp[j] != -1){
                    dp[j] = min(dp[j], 1+dp[j-coins[i-1]]);
                }
                else{// curr coin + old coins
                    dp[j] = 1+dp[j-coins[i-1]];
                }
            }
            // coin is not uaed, so past value is curr value
        }
    }
    return dp[v];
}
int main(){
	FAST_IO
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking value
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //taking value of each coin
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    
	    //calling function minimumNumberOfCoins()
	    int answer=minimumNumberOfCoins(coins,numberOfCoins,value);
	    
	    //printing "Not Possible" if answer is -1
	    //else printing answer
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}
