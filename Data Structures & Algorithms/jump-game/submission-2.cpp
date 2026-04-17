class Solution {
public:
    bool f(int ind, vector<int>& nums, vector<int>& dp){
        if(ind == 0) return true;

        if(dp[ind]!=-1) return dp[ind];

        for(int i = ind-1; i>=0; i--){
            if(nums[i]>= ind-i){
                if(f(i, nums, dp)) return true;
            }
        }


        return dp[ind] = false;

    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return f(n-1, nums, dp);

    }
};
