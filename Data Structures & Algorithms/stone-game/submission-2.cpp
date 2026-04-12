class Solution {
public:
   int  getAliceScore(int start, int end,  vector<int>&piles, vector<vector<int>>& dp){

        if(start>end){
            return 0;
        }

        if(dp[start][end]!=-1) return dp[start][end];

        int aliceTurn = (end-start+1)%2?0:1;
        int score = 0;
        if(aliceTurn){
          
               score = max(piles[start] + getAliceScore(start+1, end, piles, dp),
                 piles[end] + getAliceScore(start, end-1, piles, dp));
              
        }
        else{
            score = min(getAliceScore(start+1, end, piles, dp), getAliceScore(start, end-1,  piles, dp));
        }

        return dp[start][end] = score;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int aliceScore = getAliceScore(0, n-1,  piles, dp);

        int total = accumulate(piles.begin(), piles.end(), 0);

        int bobScore = total - aliceScore;

        return (aliceScore> bobScore);
    }
};