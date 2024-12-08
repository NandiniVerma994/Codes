class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans, int delrow[], int delcol[], int iniColor, int colToPaintWith) {
        ans[row][col] = colToPaintWith;
        int n = ans.size();
        int m = ans[0].size();
        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == iniColor) {
                dfs(nrow, ncol, ans, delrow, delcol, iniColor, colToPaintWith);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>> ans = image;
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        int iniColor = image[sr][sc];
        if(iniColor == color) {
            return image;
        }
        dfs(sr, sc, ans, delrow, delcol, iniColor, color);
        return ans;
    }
};