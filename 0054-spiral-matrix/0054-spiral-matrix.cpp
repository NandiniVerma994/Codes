class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, top = 0;
        int right = m - 1;
        int bottom = n - 1;
        vector<int> ans;
        // if its a single line for that checks are given
        while(top <= bottom && left <= right) {
            // right
            for(int i=left; i<=right; i++) {
                ans.push_back(matrix[top][i]);// top is not constant left is changing
            }
            top++;
            for(int i=top; i<=bottom; i++) {
                ans.push_back(matrix[i][right]);//row change ho rha h col constant rh rha
            }
            right--;
            if(top <= bottom) {
                for(int i=right; i>=left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
            if(left <= right) {
                for(int i=bottom; i>=top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    } 
        return ans;
    }
};