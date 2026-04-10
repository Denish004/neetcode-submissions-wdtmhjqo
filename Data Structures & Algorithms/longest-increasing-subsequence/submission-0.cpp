class Solution {
public:
    int getLIS(int ind, vector<int>&nums, vector<int>&dp){
        int n = nums.size();

       
        if(dp[ind]!=-1) return dp[ind];
       int  maxLen = 1;
        for(int i = ind+1; i<n; i++){
            
            if(nums[i]>nums[ind]){
               maxLen = max(maxLen , 1 + getLIS(i, nums, dp))   ;
            }
        }

        return dp[ind] =  maxLen;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);
        int ans = 1;

        for(int i =  0; i<n; i++){
           ans = max(ans, getLIS(i, nums, dp));
        }

        return ans;
        

    }
};
