class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> st;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(isalpha(s[i])) {
                st.push(s[i]);
            }
        }
        string res = "";
        for(int i=0; i<n; i++) {
            if(!isalpha(s[i])) {
                res += s[i];
            }
            else {
                char ch = st.top();
                st.pop();
                res += ch;
            }
        }
        return res;
    }
};