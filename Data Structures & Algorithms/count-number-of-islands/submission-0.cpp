class Solution {
public:

    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited){
        int n = grid.size();
        int m = grid[0].size();
        if(row < 0 || col <0 || row>=n || col >= m || grid[row][col]=='0' || visited[row][col]){
            return;
        }

        visited[row][col] = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int i = 0; i<4; i++){
            int newRow = row+ dx[i];
            int newCol = col +dy[i];

            dfs(newRow, newCol,grid, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n, vector<int>(m, 0));
        int count = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(i, j, grid, visited);
                    count++;
                }
            }
        }

        return count;
    }
};
