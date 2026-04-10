class Solution {
public:
    int calTriboNumber(int n, vector<int>& dp){
        if(n== 0) return 0;
        else if(n==1) return 1;
        else if(n==2) return 1;

        if(dp[n]!=-1) return dp[n];

        return dp[n] = calTriboNumber(n-1, dp) + calTriboNumber(n-2, dp) + calTriboNumber(n-3, dp);
    }
    int tribonacci(int n) {
    vector<int> dp(n+1, -1);
      return   calTriboNumber(n, dp);
    }
};