// class Solution {
// public:
//     int minimumLength(string s) {
//         unordered_map<int, int> mpp;
//         int n = s.size();
//         for(int i=0; i<n; i++) {
//             mpp[s[i]]++;
//         }
//         int totLength = 0;
//         for(auto it: mpp) {
//             if(it.second % 2 == 0) {
//                 totLength += 2;
//             }
//             else if(it.second % 2 != 0) {
//                 totLength += 1;
//             }
//         }
//     return totLength;
//     }
// };

class Solution {
public:
    int minimumLength(string s) {
        vector<int> charFrequency(26, 0);
        int totalLength = 0;
        for (char currentChar : s) {
            charFrequency[currentChar - 'a']++;
        }
        for (int frequency : charFrequency) {
            if (frequency == 0) continue;
            if (frequency % 2 == 0) {
                totalLength += 2;
            } else {
                totalLength += 1;
            }
        }
        return totalLength;
    }
};