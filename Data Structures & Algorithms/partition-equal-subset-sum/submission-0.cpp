class Solution {
public:
    bool f(int ind, vector<int>&nums, int target, vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind<0) return false;

        if(dp[ind][target]!=-1) return dp[ind][target];

        bool pick = false;
          if(nums[ind]<=target){
           pick =    f(ind-1, nums, target-nums[ind], dp);
        }

        bool notPick = f(ind-1, nums, target, dp);

        return dp[ind][target] = pick || notPick;
      
    }
    bool canPartition(vector<int>& nums) {
        int sumArr = accumulate(nums.begin(), nums.end(), 0);
        if(sumArr%2==1) return false;
        int sumSub = sumArr/2;
        
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(sumArr+1, -1));

        return f(n-1, nums, sumSub, dp);
    }
};
