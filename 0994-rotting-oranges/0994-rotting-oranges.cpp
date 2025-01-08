class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //as we have to count the number of minutes for each traversal so use bfs
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    //row, col, time
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else {
                    vis[i][j] = 0;
                }
            }
        }

        int tm = 0;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,+1,0,-1};
        while(!q.empty()) {
            //t records the time of current orange
            //tm records the time of taken by overall oranges
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = delrow[i] + r;
                int ncol = delcol[i] + c;
                if(nrow >= 0 && nrow <n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                    q.push({{nrow, ncol},t+1});
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