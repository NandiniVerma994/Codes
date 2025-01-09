// class Solution {
// public:
//     void dfs(int row, int col, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &board) {
//         vis[row][col] = 1;
//         int delrow[] = {-1,0,1,0};
//         int delcol[] = {0,1,0,-1};
//         for(int i=0; i<4; i++) {
//             int nrow = row + delrow[i];
//             int ncol = col + delcol[i];
//             if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O') {
//                 dfs(nrow, ncol, n, m, vis, board);
//             }
//         }
//     }
//     //STeps involved
//     //Mark all the boundary first as O and do a dfs traversal in all four directions so that anyone having boundary as O is not converted to x
//     void solve(vector<vector<char>>& board) {
//         int n = board.size();
//         int m = board[0].size();
//         vector<vector<int>> vis(n, vector<int>(m,0));
//         for(int j=0; j<m; j++) {
//             if(vis[0][j] == 0 && board[0][j] == 'O') {
//                 dfs(0, j, n, m, vis, board);
//             }
//             if(vis[n-1][j] == 0 && board[n-1][j] == 'O') {
//                 dfs(n-1, j, n, m, vis, board);
//             }
//         }

//         for(int i=0; i<n; i++) {
//             if(vis[i][0] == 0 && board[i][0] == 'O') {
//                 dfs(i, 0, n, m, vis, board);
//             }
//             if(vis[i][m-1] == 0 && board[i][m-1] == 'O') {
//                 dfs(i, m-1, n, m, vis, board);
//             }
//         }
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 if(board[i][j] == 'O' && vis[i][j] == 0) {
//                     board[i][j] = 'X';
//                 }
//             }
//         }
//     }
// };

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        //marking all the boundary rows and col as visited
        for(int i=0; i<n; i++) {
            for(int j=0;j < m; j++) {
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    if(board[i][j] == 'O') {
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,+1,0,-1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            //bfs
            for(int i=0; i<4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                } 
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};