class Solution {
public:
    int calTriboNumber(int n, vector<int>& dp){
        if(n== 0) return 0;
        else if(n==1) return 1;
        else if(n==2) return 1;

        if(dp[n]!=-1) return dp[n];

        return dp[n] = calTriboNumber(n-1, dp) + calTriboNumber(n-2, dp) + calTriboNumber(n-3, dp);
    }
    int tribonacci(int n) {
    // vector<int> dp(n+1, -1);

    // dp[0] = 0;
    // dp[1] = 1;
    // dp[2] = 1;

  
    // for(int i = 3; i<=n; i++){
    //     dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    // }
    //   return dp[n];
    // }

    int a = 0, b = 1, c= 1;

    if(n==0) return a;
    if(n==1) return b;
    if(n==2) return c;

    for(int i = 3; i<=n; i++){
        int temp;
        temp = a + b + c;
        a = b;
        b= c;
        c= temp;

    }

    return c;
    }
};