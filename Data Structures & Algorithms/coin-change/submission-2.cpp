class Solution {
public:
    int giveMinCoins(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
      

        if(amount == 0) return 0;
        else if(ind==0){
            int rem = amount%(coins[ind]);
            if(rem == 0){
                return amount/(coins[ind]);
            }

            return 1e8;
        }


        if(dp[ind][amount]!=-1) return dp[ind][amount];

        int pick = 1e8;
        if(coins[ind] <= amount){
          pick = 1 + giveMinCoins(ind, amount-coins[ind], coins, dp);

        }

        int notPick = giveMinCoins(ind-1, amount, coins, dp);


        return dp[ind][amount] = min(pick, notPick);

        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans =giveMinCoins(n-1, amount, coins, dp); 

        if(ans ==1e8) return -1;
        else return ans;
    }
};
