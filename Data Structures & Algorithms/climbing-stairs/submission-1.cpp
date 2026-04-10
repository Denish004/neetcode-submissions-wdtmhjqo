class Solution {
public:
    int calSteps(int currStair, vector<int>& dp){
        if(currStair == 0) return 1;
        else if(currStair<0) return 0;

        if(dp[currStair]!= 0) return dp[currStair];

        return dp[currStair] = calSteps(currStair-1, dp) + calSteps(currStair-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
          return  calSteps(n, dp);
    }
};
