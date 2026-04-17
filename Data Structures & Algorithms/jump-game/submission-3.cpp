class Solution {
public:
    bool f(int ind, vector<int>& nums, vector<int>& dp){
        if(ind == 0) return true;

        if(dp[ind]!=-1) return dp[ind];

        for(int i = ind-1; i>=0; i--){
            if(nums[i]>= ind-i){
                if(f(i, nums, dp)) return dp[ind]= true;
            }
        }


        return dp[ind] = false;

    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, -1);

        // return f(n-1, nums, dp);

        int goal = n-1;

        for(int i  = n-2;i>=0; i--){
            if(i + nums[i] >= goal){
                goal = i;
            }
        }
        return goal==0;
    }
};
