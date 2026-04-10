class Solution {
public:
    int calLongIncPath(int row, int col, vector<vector<int>>&matrix, vector<vector<int>>&dp){
      

        if(dp[row][col]!=-1) return dp[row][col];

        int dx[4]= {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        int maxLength = 1;
        for(int i = 0; i<4; i++){
            int newX = row + dx[i];
            int newY = col + dy[i];

          if(newX >= 0 && newX<matrix.size() && newY >=0 && newY < matrix[0].size() && matrix[newX][newY] > matrix[row][col]){
             maxLength = max(maxLength, 1 + calLongIncPath(newX, newY, matrix, dp));

          }

           
        }

        return dp[row][col] = maxLength;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    int maxLength = 1;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    for(int row = 0; row<matrix.size(); row++){
        for(int col = 0; col<matrix[0].size(); col++){
            maxLength = max(maxLength, calLongIncPath(row, col, matrix, dp)); 

        }
    }
      return maxLength;
    }
};
