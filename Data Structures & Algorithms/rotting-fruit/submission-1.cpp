class Solution {
public:
    int BFS(vector<vector<int>>& grid){
          int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;
        int fresh = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        if (fresh == 0)
              return 0;

        int timer = 0;

        int dx[4] = {1,-1, 0,0};
        int dy[4] = {0,0, 1, -1};

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i<size; i++){
               pair<int,int> p =  q.front();
               q.pop();

               for(int i = 0; i<4; i++){
                int newX = p.first + dx[i];
                int newY = p.second + dy[i];

                if(newX >=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]==1){
                    q.push({newX, newY});
                    grid[newX][newY]= 2;
                    fresh--;
                }
               }
            }

            timer++;
        }

        

        return (fresh==0)?timer-1:-1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
      

        return BFS(grid);
    }
};
