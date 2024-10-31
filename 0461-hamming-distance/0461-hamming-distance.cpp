class Solution {
public:
    int hammingDistance(int x, int y) {
        int xor1 = x ^ y;
        int cnt = 0;
        for(int i=0; i<31; i++) {
            if(xor1 & (1 << i)) cnt++;
        }
        return cnt;
    }
};