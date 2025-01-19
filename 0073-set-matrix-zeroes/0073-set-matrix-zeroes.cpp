class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    //marking the first row to be 0
                    matrix[i][0] = 0;
                //marking the first col to be 0 but col0 upr h so uske liye alag condition
                    if(j != 0) {
                        matrix[0][j] = 0;
                    }
                    else {
                        col0 = 0;
                    }
                }

            }
        }
        //now marks excluding the first row and column
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(matrix[i][j] != 0) {
                    if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        //ab sirf phla col ka phla element dekho
        if(matrix[0][0] == 0) {
            for(int j=0; j<m; j++) {
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0) {
            for(int i=0; i<n; i++) {
                matrix[i][0] = 0;
            }
        }

    }
};