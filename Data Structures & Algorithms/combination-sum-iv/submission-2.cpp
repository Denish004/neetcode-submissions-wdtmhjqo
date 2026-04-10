class Solution {
public:
    int calWays(int target, vector<int>&nums, vector<int>&dp){
        if(target == 0) return 1;
        
        int countWays = 0;

        if(dp[target]!=-1 ) return dp[target];
        for(int i = 0; i<nums.size(); i++ ){
            int remTarget = target - nums[i];
            if(remTarget >=0){
                countWays  +=  calWays(remTarget, nums, dp);
            }
        }


        return dp[target] = countWays;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(target+1, 0);
    //    return  calWays(target, nums, dp);

        dp[0] = 1;

        for(int t = 1; t<=target; t++){
            dp[t] = 0;
            for(int i = 0; i<nums.size(); i++){
                 int remTarget = t - nums[i];
                if(remTarget >=0){
                dp[t]  +=  dp[remTarget];
                }
            }
        }


        return dp[target];


        


    }
};