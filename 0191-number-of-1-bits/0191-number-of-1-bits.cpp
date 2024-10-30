class Solution {
public:
    int hammingWeight(int n) {
        string res = "";
        while(n > 0) {
            int rem = n % 2;
            res += rem + '0';
            n = n / 2;
        }
        int cnt = 0;
        for(int i=0; i<res.size(); i++) {
            if(res[i] == '1') {
                cnt++;
            }
        }
        return cnt;
    }
};