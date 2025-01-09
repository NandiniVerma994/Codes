class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int delrow[], int delcol[]) {
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board, delrow, delcol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,1,0,-1};
        vector<vector<int>> vis(n, vector<int>(m,0));
        //marking boundaries as visited if it contains big O's 
        //marking boundary rows
        for(int j=0; j<m; j++) {
            //marking first row
            if(!vis[0][j] && board[0][j] == 'O') {
                //mark its corresponding neigbours
                dfs(0, j, vis, board, delrow, delcol);
            }
            //marking last row
            if(!vis[n-1][j] && board[n-1][j] == 'O') {
                dfs(n-1, j, vis, board, delrow, delcol);
            }
        }
        //marking boundary cols
        for(int i=0; i<n; i++) {
            //marking first col
            if(!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, delrow, delcol);
            }
            //marking last col
            if(!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1, vis, board, delrow, delcol);
            }
        }
        //now again traverse through the whole board to check if any where O comes then mark it as X bcz boundary ones(along with its neighbours) are already marked that they cant be converted to X
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
        //no returning board as the return type is void so need to make changes in the given matrix only
    }
};