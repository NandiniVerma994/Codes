class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        //we define a set to avoid doing linear search
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            for(int i=0; i<word.size(); i++) {
                char original = word[i];
                for(char ch='a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    //exists in the set
                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};