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
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        int ans =giveMinCoins(n-1, amount, coins, dp); 


        // for(int ind = 0; ind<n; ind++){
        //     for(int remAmount = 0 ; ramount <)
        // }


        for(int amnt = 1; amnt <= amount; amnt++ ){
            int rem = amnt%(coins[0]);
            if(rem == 0){
                dp[0][amnt] = amnt/(coins[0]);
            }
            else dp[0][amnt] = 1e8;
        }

    for(int ind = 1; ind<n; ind++){
        for(int amnt = 0; amnt<=amount; amnt++){
             int pick = 1e8;
        if(coins[ind] <= amnt){
          pick = 1 + dp[ind][amnt-coins[ind]];

        }

        int notPick = dp[ind-1][amnt];


        dp[ind][amnt] = min(pick, notPick);

        }
    }

        if(dp[n-1][amount] ==1e8) return -1;
        else return dp[n-1][amount];
    }
};
