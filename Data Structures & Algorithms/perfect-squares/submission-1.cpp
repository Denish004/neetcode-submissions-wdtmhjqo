class Solution {
public:
    int calMinNumbers(int target, vector<int>&nums, vector<int>&dp){
        if(target == 0)  return 0;

        if(dp[target]!=-1) return dp[target];

        int finalMin = 1e8;
        for(int i = 0; i<nums.size(); i++){
        
            if(nums[i]<=target){
                finalMin = min(finalMin,   1  +  calMinNumbers(target-nums[i], nums, dp));
            }
        }

        return dp[target] = finalMin;
    }
    int numSquares(int n) {
        vector<int> sqNums;


        for(int i = 1; i*i <=n;  i++){
            sqNums.push_back(i*i);
        }

        vector<int>dp(n+1, 1e8);
        dp[0] = 0;

        for(int target = 1; target<=n; target++){
              dp[target] = 1e8;
        for(int i = 0; i<sqNums.size(); i++){
        
            if(sqNums[i]<=target){
                dp[target] = min(dp[target],   1  +  dp[target-sqNums[i]]);
            }
        }
        }
        return dp[n];
    //    return  calMinNumbers( n, sqNums, dp);
    }
};