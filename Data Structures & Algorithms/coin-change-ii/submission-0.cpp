class Solution {
public:
    int f(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(ind == 0){
            if(amount%coins[ind]==0) return 1;
            else return 0;
        }
        if(amount == 0){
            return 1;
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int pick = 0;
        if(coins[ind]<=amount){
            pick =  f(ind, amount-coins[ind], coins, dp);
        }

        int notPick = f(ind-1, amount, coins, dp);

        return dp[ind][amount] = pick + notPick;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        return f(n-1, amount, coins, dp);
    }
};
