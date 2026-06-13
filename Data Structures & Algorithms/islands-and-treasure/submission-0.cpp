class Solution {
public:
    void BFS(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        int step = 1;

        int dy[4] = {0, 0, 1, -1};
        int dx[4] = {1, -1, 0, 0};

        while(!q.empty()){


            int size = q.size();

            for(int i = 0; i<size; i++){

            pair<int,int> p = q.front();
            q.pop();


            for(int i = 0; i<4; i++){
            int newRow = p.first + dx[i];
            int newCol = p.second + dy[i];

            if(newRow >=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==INT_MAX){
                grid[newRow][newCol]= step;
                q.push({newRow, newCol});
            }

            }
          

            }

            step++;


        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        

        int n = grid.size();
        int m = grid[0].size();

      

        BFS(grid);
    }
};
