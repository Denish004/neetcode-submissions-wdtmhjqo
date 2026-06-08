class Solution {
public:

    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited){
        int n = grid.size();
        int m = grid[0].size();
        if(row < 0 || col <0 || row>=n || col >= m || grid[row][col]==0 || visited[row][col]){
            return 0;
        }

        visited[row][col] = 1;
        int count = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int i = 0; i<4; i++){
            int newRow = row+ dx[i];
            int newCol = col +dy[i];

           count+= dfs(newRow, newCol,grid, visited);
        }

        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n, vector<int>(m, 0));
        int ans = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                   ans = max(ans, dfs(i, j, grid, visited));
                   
                }
            }
        }

        return ans;
    
    }
};


