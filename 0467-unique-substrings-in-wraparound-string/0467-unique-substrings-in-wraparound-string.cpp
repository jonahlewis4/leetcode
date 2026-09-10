class Solution {
    static inline uint8_t char2Position(char c) {
        return (c - 'a')%26;
    }
public:
    int findSubstringInWraproundString(string s) {
        vector<int> longest(26, 0);
        char firstChar = s.front();
        longest[firstChar - 'a'] = 1;
        int streak = 1;
        for(int i = 1; i < s.size(); i++) {
            char curChar = s[i];
            uint8_t pos1 = char2Position(s[i-1] + 1);
            uint8_t pos2 = char2Position(curChar);
            if(pos1 == pos2) {
                streak++;
            } else {
                streak = 1;
            }
            longest[curChar - 'a'] = max(streak, longest[curChar - 'a']);

        }

        return accumulate(longest.begin(), longest.end(), 0);
    }
};