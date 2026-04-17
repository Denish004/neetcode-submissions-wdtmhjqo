class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int currMax  = 0, maxSum = INT_MIN;
        int currMin = 0, minSum = INT_MAX;
        int total = 0;

        for(int i = 0; i<n; i++){

           currMax = max(currMax + nums[i], nums[i]);
           currMin =min(currMin + nums[i], nums[i]);

           maxSum = max(currMax, maxSum);
           minSum = min(currMin, minSum);

           total+=nums[i];


        }

        return (maxSum>0)?max(maxSum, total - minSum):maxSum;
    }
};