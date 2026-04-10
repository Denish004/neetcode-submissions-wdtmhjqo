class Solution {
public:
    int calMaxAmount( vector<int> nums){
    //     if(ind<0) return 0;
    //    if(flag == 0 && ind == 0 ) return 0;
       

    //     if(dp[ind][flag]!=-1) return dp[ind][flag];

    //     int Pick = nums[ind]+ calMaxAmount(ind-2, nums, flag, dp);
    //     int notPick = 0 + calMaxAmount(ind-1, nums, flag ,dp);


    //     return dp[ind][flag]= max(Pick, notPick);

    int n = nums.size();
    
    int prev2 = nums[0];
    if(n==1) return prev2;
    
    int prev1 = max(nums[0], nums[1]);

    for(int i = 2; i<n; i++){
      int curr = max(    nums[i]+ prev2, prev1);

      prev2 = prev1;
      prev1 = curr;
    }


    return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        if(n==1 ) return nums[0];
        if(n==2 ) return max(nums[0], nums[1]);
         
         int skipFirst = calMaxAmount(vector<int>(nums.begin()+1, nums.end()));
         int skipLast = calMaxAmount(vector<int>(nums.begin(), nums.end()-1));




        
        return max(skipFirst, skipLast);



    }
};