class Solution {
public:
    string truncateSentence(string s, int k) {
        int wordCount = 0;
        for(int i = 1; i < s.size(); i++){
            char c = s[i];
            if(c == ' ') {
                wordCount++;
                if(wordCount == k) {
                    return s.substr(0, i);
                }
            }
        }

        return s;
    }
};