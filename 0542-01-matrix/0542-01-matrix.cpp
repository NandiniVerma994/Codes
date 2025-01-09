class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        //creating a matrix for marking the visited node
        vector<vector<int>> vis(n, vector<int>(m,0));
        //creating a matrix for storing the nearest ones
        vector<vector<int>> dist(n, vector<int>(m,0));
        queue<pair<pair<int,int>, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                //marking the visited matrix with 1's by traversing through 
                //the grid(only where 1's are given)
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                else {
                    vis[i][j] = 0;
                }
            }
        }

        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            //marking the distance matrix with the steps
            dist[row][col] = steps;
            //traversing its neighbours
            for(int i=0; i<4; i++) {
                int nrow =row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        return dist;


    }
};