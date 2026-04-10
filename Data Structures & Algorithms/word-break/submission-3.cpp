class Solution {
public:



    // neetcode    n*n*m*len

    //             n*m*len





    // neet, code, nee


    // 0..........ind...........n-1;

    // ind,
    // ind ind+1
    // ind ind+1 ind+2

    // ind ind+1 ..........ind+n-1;

    bool checkWordBreak(int ind, string&s, vector<string>&wordDict, vector<int>&dp){
    
        int n = s.size();

        if(ind == n) return true;

        if(dp[ind]!=-1) return dp[ind];
        for(auto w : wordDict){
            bool isPossible = false;
            if(ind + w.size()<= n && s.substr(ind, w.size())==w){
                isPossible =  checkWordBreak(ind+w.size(),s ,wordDict, dp);
            }
            if(isPossible) return dp[ind] = true;
        }

        return dp[ind] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<int> dp(n, -1);
         return checkWordBreak(0, s, wordDict, dp);


        // dp[n] = 1;

        // for(int ind = n-1; ind>=0; ind--){
        //     for(auto w : wordDict){

        //         if(ind+w.size()<=n && s.substr(ind, w.size())==w ){
        //             dp[ind] =  dp[ind + w.size()];
        //         }
        //         if(dp[ind]==1) break;

        //     }
        // }
        // return dp[0];

        // vector<int>dp(n+1, 0);
        // dp[n] = 1;

        // for(int i = n-1; i>=0; i--){
        //     for(auto w : wordDict){
        //         if(i+w.size()<=n && s.substr(i, w.size())==w){
        //             dp[i] = dp[i+w.size()];
        //         }
        //         if(dp[i]==1) break;
        //     }
        // }

        // return dp[0];
    }
};
