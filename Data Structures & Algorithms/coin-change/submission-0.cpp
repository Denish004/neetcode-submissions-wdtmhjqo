class Solution {
public:
    int giveMinCoins(int ind, int amount, vector<int>&coins){
      

        if(amount == 0) return 0;
        else if(ind==0){
            int rem = amount%(coins[ind]);
            if(rem == 0){
                return amount/(coins[ind]);
            }

            return 1e8;
        }


        int pick = 1e8;
        if(coins[ind] <= amount){
          pick = 1 + giveMinCoins(ind, amount-coins[ind], coins);

        }

        int notPick = giveMinCoins(ind-1, amount, coins);


        return min(pick, notPick);

        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        if(giveMinCoins(n-1, amount, coins)==1e8) return -1;
        else return giveMinCoins(n-1, amount, coins);
    }
};
