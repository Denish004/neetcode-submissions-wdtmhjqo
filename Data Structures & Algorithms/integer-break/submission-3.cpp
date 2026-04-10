class Solution {
public:
    int calProduct(int target,int n, vector<int>&dp){
         if(target<=1) return target;


         if(dp[target]!=-1) return dp[target];

        int maxProduct = target==n ? 0 : target;

        for(int no = 1; no<=target-1;no++){
            maxProduct = max(maxProduct, calProduct(no,n,  dp)*calProduct(target-no,n, dp));
        }

        return dp[target] = maxProduct;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1, -1);
       
    return calProduct(n,n,  dp);


        //    12
        //    1     11

        //    2     10

        //    3      9


        //    11      1
    }
};