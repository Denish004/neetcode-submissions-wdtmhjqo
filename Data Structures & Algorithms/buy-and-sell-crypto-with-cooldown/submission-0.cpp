class Solution {
public:
    int f(int ind, int option, vector<int>& prices, vector<vector<int>>& dp){
        int n = prices.size();
        if(ind>=n){
            return 0;
        }

        if(dp[ind][option]!=-1) return dp[ind][option];
      

        int profit = 0;
        if(option == 0){
            profit = f(ind+1, 1, prices, dp) - prices[ind];
            profit =max(profit,  f(ind+1, option, prices, dp));
        }
        else{
            profit = f(ind+2, 0, prices, dp) + prices[ind];
            profit =max(profit,  f(ind+1, option, prices, dp));
        }

        return dp[ind][option] = profit;

    }
    int maxProfit(vector<int>& prices) {
        
        int n  = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));

        return f(0, 0, prices, dp);
    }
};
