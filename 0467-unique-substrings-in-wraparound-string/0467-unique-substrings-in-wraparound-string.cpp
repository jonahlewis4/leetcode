class Solution {
    uint8_t char2Position(char c) {
        return (c - 'a')%26;
    }
public:
    int findSubstringInWraproundString(string s) {
        int res = 0;
        for(char c = 'a'; c <= 'z'; c++) {
            int start = 0;
            int end = 1;
            int best = 0;
            while(start < s.size()) {
                while(start < s.size() && s[start] != c) {
                    start++;
                    end = start + 1;
                }

                if(start >= s.size()) {
                    break;
                }

                bool streak = false;

                if(end < s.size()) {
                    char prev = s[end-1];
                    uint8_t prevVal = char2Position(prev+1);
                    uint8_t curVal = char2Position(s[end]);
                    streak = prevVal == curVal;
                }
                
                if(!streak) {
                    best = max(end - start, best);
                    start=end;
                }

                end++;
            }
            res += best;
        }

        return res;
    }
};