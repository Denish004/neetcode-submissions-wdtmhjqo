class Solution {
public:

    void dfs(int r, int c, vector<vector<int>>& visited, int prevHeight, vector<vector<int>>&heights){
        int n = heights.size();
        int m = heights[0].size();

        if(r<0 || r >=n || c<0 || c>=m || visited[r][c]==1 || heights[r][c] < prevHeight){
            return;
        }
        visited[r][c] = 1;

        dfs(r+1, c, visited, heights[r][c], heights);
         dfs(r, c+1, visited, heights[r][c], heights);
          dfs(r-1, c, visited, heights[r][c], heights);
           dfs(r, c-1, visited, heights[r][c], heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>paci(n, vector<int>(m, 0));
        vector<vector<int>>atlan(n, vector<int>(m, 0));


        for(int c = 0; c<m; c++){
            dfs(0, c, paci, heights[0][c], heights);
            dfs(n-1, c, atlan, heights[n-1][c], heights);
        }
         for(int r = 0; r<n; r++){
            dfs(r, 0, paci, heights[r][0], heights);
            dfs(r, m-1, atlan, heights[r][m-1], heights);
        }

        vector<vector<int>>result;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(paci[i][j]==1 && atlan[i][j]==1){
                    result.push_back({i,j});
                }
            }
        }
        return result;

    }
};
