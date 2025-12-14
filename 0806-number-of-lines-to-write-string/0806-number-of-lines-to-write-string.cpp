class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int lineLen = 0;
        for(const char c : s) {
            int len = widths[c - 'a'];
            lineLen += len;
            if(lineLen > 100) {
                lines++;
                lineLen = len;
            }
        }

        return {lines, lineLen};
    }
};