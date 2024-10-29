class Solution {
public:
    string convertToBinary(int num) {
        string res = "";
        while(num > 0) {
            int rem = num % 2;
            num = num / 2;
            res += rem + '0';
        }
        return res;
    }

    vector<int> countBits(int n) {
        vector<int> bits;
        for(int i=0; i<=n; i++) {
            string res = convertToBinary(i);
            int cnt = 0;
            int size = res.size();
            for(int i=size-1; i>=0; i--) {
                if(res[i]-'0' && 1 == 1) {
                    cnt++;
                }
            }
            bits.push_back(cnt);
        }
        return bits;
    }
};