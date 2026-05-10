class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int best = 0;
        for(const char c : s) {
            if(c == '(') {
                open++;
            } else if (c == ')') {
                open--;
            }
            best = max(best, open);
        }
        return best;
    }
};