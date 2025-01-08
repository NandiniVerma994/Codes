class Solution {
public:
    // Step1: Put all the rotten oranges into the queue
    // Step2: Put all the oranges in the 4 directions(if fresh) in the queue
    // Step3: Check at last if all oranges are rotten

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }

        int tm = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            tm = max(t,tm);
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n &&  ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return tm;
        

    }
};