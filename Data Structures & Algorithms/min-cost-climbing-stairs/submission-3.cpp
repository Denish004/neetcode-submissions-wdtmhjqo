class Solution {
public:
    int calMinCost(int ind, vector<int>&cost, vector<int>&dp){
      if(ind >= cost.size()  ) return 0 ;
      
    if(dp[ind]!=-1) return dp[ind];
      int jump1 = calMinCost(ind+1, cost, dp) + cost[ind];

      int jump2 = calMinCost(ind+2, cost, dp ) + cost[ind];

      return dp[ind] = min(jump1, jump2);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2, 0);
      
        for(int ind = n-1; ind>=0; ind--){
            // int jump1 = dp[ind+1] + cost[ind];
            // int jump2 = dp[ind+2] + cost[ind];
            int jump = cost[ind] + min(dp[ind+1], dp[ind+2]);

            dp[ind] = jump;
        }

        return min(dp[0], dp[1]); 
        // return min(calMinCost(0, cost, dp) , calMinCost(1, cost, dp));
    }
};
