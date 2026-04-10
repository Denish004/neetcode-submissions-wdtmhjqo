class Solution {
public:
   int calScore(int ind, int player, vector<vector<int>>&dp, vector<int>&stoneValue){
    int n = stoneValue.size();

    if(ind>=n) return 0;

    if(dp[ind][player]!=-1) return dp[ind][player];
    int total = 0;
    int aliceScore = (player==0)?INT_MIN:INT_MAX;
      for(int i = 0; i<3 && ind+i<n; i++){
        total += stoneValue[ind+i];

        if(player == 0){
             aliceScore = max(aliceScore ,  total + calScore(ind+i+1, !player, dp, stoneValue));
        }else{
            aliceScore = min(aliceScore, calScore(ind+i+1, !player, dp, stoneValue));
        }

      }

      return dp[ind][player] = aliceScore;
   }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<vector<int>>dp(n, vector<int>(2, -1));

        int aliceScore = calScore(0, 0, dp, stoneValue);
        int total = accumulate(stoneValue.begin(), stoneValue.end(), 0);

        int bobScore = total - aliceScore;

        if(aliceScore == bobScore) return "Tie";

        return (aliceScore>bobScore)?"Alice":"Bob";
        // vector<int> dp(n+1, INT_MIN);
        // dp[n] = 0;

       
        // for(int i = n-1; i>=0; i--){
        //     int total = 0;
        //     for(int j = 0; j<3 && i+j<n; j++){
        //         total+=stoneValue[i+j];
        //         dp[i] = max(dp[i], total - dp[i+j+1]);
        //     }
            

        // }
        // if(dp[0]==0) return "Tie";
        // return dp[0]>0?"Alice":"Bob";
    } 







                                            
};