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
        vector<int> dp(n, -1);
        return min(calMinCost(0, cost, dp) , calMinCost(1, cost, dp));
    }
};
