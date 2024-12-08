class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //passing row, col and time
        queue<pair<pair<int, int>,int>> q;
        //creating a visited matrix
        int vis[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                //if its 2 then mark is at visited as well as push it into the q , if its not 2 then mark vis as 0
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else {
                    vis[i][j] = 0;
                }
            }
        }

        //traversing through its neighbour
        int tm = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {//agr oranges fresh h means grid 1 marked h
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
                }
            }
        }

        //check if there exists any such cell in the grid which is still fresh then return -1
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