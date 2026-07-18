class Solution {
public:

    void dfs(int r, int c, vector<vector<int>>& visited, vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        if(r<0 || c<0 || r>=n || c>=m || board[r][c]=='X'  || visited[r][c]==1){
            return;
        }

        visited[r][c] = 1;


        dfs(r+1,c, visited, board);
        dfs(r, c+1, visited,board);
        
        dfs(r-1,c, visited, board);
        dfs(r, c-1, visited,board);



    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();


        vector<vector<int>>visited(n, vector<int>(m, 0));

        for(int c = 0; c<m ; c++){
            if(board[0][c]=='O' && visited[0][c] == 0){
                dfs(0, c, visited, board);
            }
            if(board[n-1][c]=='O' && visited[n-1][c] == 0){
                dfs(n-1, c, visited, board);
            }

        }

        for(int r = 0; r<n ; r++){
            if(board[r][0]=='O' && visited[r][0] == 0){
                dfs(r, 0, visited, board);
            }
            if(board[r][m-1]=='O' && visited[r][m-1] == 0){
                dfs(r, m-1, visited, board);
            }

        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};
