class Solution {
public:
    int calMaxAmount(int ind, vector<int>&nums, vector<int>& dp){
        if(ind<0) return 0;
        else if(ind == 0) return nums[0];

        if(dp[ind]!=-1) return dp[ind];

        int Pick = nums[ind] + calMaxAmount(ind-2, nums, dp);
        int notPick = 0 + calMaxAmount(ind-1, nums, dp);


        return dp[ind] = max(Pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int ind = 2; ind<=n-1; ind++){
            
        int Pick = nums[ind] + dp[ind-2];
        int notPick = 0 + dp[ind-1];

        dp[ind] = max(Pick, notPick);
        }
       return  dp[n-1];
    }
};
