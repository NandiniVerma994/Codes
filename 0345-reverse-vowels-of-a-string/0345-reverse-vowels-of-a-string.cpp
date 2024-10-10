class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        stack<int> st;
        for(int i=0; i<n; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                st.push(s[i]);
            }
        }
        string res = "";
        for(int i=0; i<n; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                if(!st.empty()) {
                    char ch = st.top();
                    st.pop();
                    res += ch;
                }
            }
            else {
                res += s[i];
            }
        }
        return res;
    }
};