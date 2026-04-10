class Solution {
public:
    int calPaths(int i, int j, vector<vector<int>> obstacleGrid, vector<vector<int>>&dp){
         int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || obstacleGrid[i][j]==1){
            return 0;
        }

        if(i== 0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        int left = calPaths(i, j-1, obstacleGrid, dp);
        int up = calPaths(i-1, j, obstacleGrid, dp);

        return dp[i][j] = left + up;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>>dp(n, vector<int>(m, -1));

        return calPaths(n-1, m-1, obstacleGrid, dp);
    }
};