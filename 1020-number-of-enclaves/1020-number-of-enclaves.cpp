class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,(vector<int>(m,0)));
        //marking all the boundary rows and col as visited
        for(int i=0; i<n; i++) {
            for(int j=0;j < m; j++) {
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    if(grid[i][j] == 1) {
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
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                } 
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};