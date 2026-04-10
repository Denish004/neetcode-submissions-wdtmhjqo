class Solution {
public:
    int getLongCommSub(int i, int j, string& s1, string & s2, vector<vector<int>>& dp){

        if(i<0 || j<0 ){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];
     
        if(s1[i]==s2[j]){
            return 1 + getLongCommSub(i-1, j-1, s1, s2, dp);
        }

       return dp[i][j] = max(getLongCommSub(i-1, j, s1, s2, dp) , getLongCommSub(i, j-1, s1, s2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return getLongCommSub(n-1, m-1, text1, text2, dp);
    }
};
