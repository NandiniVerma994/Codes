class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;
        int flag = 0;
        for(int i=n-1; i>=0; i--) {
            if(isalpha(s[i]) && flag == 0) {
                count++;
            }
            else if(count != 0 && s[i] == ' ') {
                flag = 1;
            }
            else if(flag == 1) {
                break;
            }
            else {
                continue;
            }
        }
        return count;
    }
};