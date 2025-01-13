class Solution {
public:
    int minimumLength(string s) {
        unordered_map<int, int> mpp;
        int n = s.size();
        for(int i=0; i<n; i++) {
            mpp[s[i]]++;
        }
        int totLength = 0;
        for(auto it: mpp) {
            if(it.second % 2 == 0) {
                totLength += 2;
            }
            else if(it.second % 2 != 0) {
                totLength += 1;
            }
        }
    return totLength;
    }
};