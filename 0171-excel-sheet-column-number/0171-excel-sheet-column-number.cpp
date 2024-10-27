class Solution {
public:
//Colum Number = (L1*26^n-1) + (L2*26^n-2) 
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int colNum = 0;
        int j = 1;
        for(int i=0; i<n; i++) {
            int num = columnTitle[i] - 'A' + 1;
            colNum += (num * pow(26, n-j));
            j++;
        }
        return colNum;
    }
};