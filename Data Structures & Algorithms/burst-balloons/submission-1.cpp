class Solution {
public:
    int f(int l, int r, vector<int>&nums, vector<vector<int>>& dp){
        if(l>r) return 0;

        int maxValue = 0;

        if(dp[l][r]!=-1) return dp[l][r];

        for(int i = l; i<=r; i++){
            int val = f(l, i-1, nums, dp) + f(i+1, r, nums, dp) + nums[l-1]*nums[i]*nums[r+1];
            maxValue = max(val, maxValue);
        }


        return dp[l][r] = maxValue;

    }
    int maxCoins(vector<int>& nums) {
       
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
         int n = nums.size();

         vector<vector<int>>dp(n-1, vector<int>(n-1, -1));
        return f(1, n-2, nums, dp);
    }
};
