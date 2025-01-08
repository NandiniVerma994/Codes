class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int iniColor, int delRow[], int delCol[]) {
        //sbse first me hi jiska row aur col diya h agr wo initial color h to usko new colour se paint kr do
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i=0; i<4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                //if wo image initial number se marked h aur ans visited nhi h toh usko new number se rang denge
                if(nrow >= 0 && nrow <n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                    dfs(nrow, ncol, ans, image, newColor, iniColor, delRow, delCol);
                }
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {//color is the one with which it needs to be painted
        //jo initial colour h agr wohi rhega toh hi paint krenge
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        dfs(sr, sc, ans, image, color, iniColor, delRow, delCol);
        return ans;
    }
};