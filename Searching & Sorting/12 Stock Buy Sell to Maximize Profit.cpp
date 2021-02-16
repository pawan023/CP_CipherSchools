// Stock Buy Sell to Maximize Profit

#include<bits/stdc++.h>
using namespace std;

// 1> Best Time to Buy and Sell Stock I (1 transaction)
// time: O(N) space: O(1) 
	int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int current_max=0, max_profit=0;
        for(int i=1;i<n;i++){
            current_max += prices[i] - prices[i-1];
            if(current_max < 0) current_max =0;
            if(current_max > max_profit) max_profit = current_max;
        }
        return max_profit;
        /*
        int min_cost = INT_MAX, max_profit = 0;
        for(int i=0;i<n;i++){
            min_cost = min(prices[i], min_cost);
            max_profit = max(max_profit, prices[i]-min_cost);
        }
        return max_profit;
        */
    }
    
// 2> Best Time to Buy and Sell Stock II (any transaction)
	int maxProfit(vector<int>& prices) {
        int n=prices.size(), profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]) 
				profit += prices[i]-prices[i-1];
        }
        return profit;
    }
    // priting the days we r buying and selling stocks
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        vector<vector<int>> stockPlan;
        int buyday=0, sellday=0;
        for(int i=1; i<n; i++){
            int flag = false; // to check if we are buying and selling on diff days
            // if we have alrdy buyed a stock  we check for >=0 profit, else >0 profit
            while( i<n && ((A[i]-A[sellday]>0)or(flag && A[i]-A[sellday]>=0)) ){
                flag = true;
                i++; sellday++;
            }
            if(flag) stockPlan.push_back({buyday,sellday});
            buyday = i, sellday = i;
        }
        return stockPlan;
    }
    
int main(){
    vector<int> prices = { 100, 180, 260, 310, 40, 535, 695 };
    int n = prices.size();
    cout << maxProfit(prices);
    return 0;
}

