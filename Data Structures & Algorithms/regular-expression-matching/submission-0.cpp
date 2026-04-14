class Solution {
public:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        int n = s.size(), m = p.size();
        if(i>=n && j>=m ) return true;
        else if(j>=m) return false;

        if(dp[i][j]!=-1) return dp[i][j];

        bool match =(i<n) && (s[i]==p[j] || p[j]=='.');

        if(j+1<m && p[j+1]=='*'){
          return  dp[i][j]= f(i, j+2, s, p, dp) || (match && f(i+1, j, s, p, dp));
        }

        if(match){
            return dp[i][j] = f(i+1, j+1, s, p, dp);
        }
        return dp[i][j]= false;

    }
    bool isMatch(string s, string p) {
     int n = s.size(), m = p.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        
       return f(0, 0, s, p, dp);

    }
};
