class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevCount = 0;
        int curCount = 1;
        int res = 0;
        char prev = s.front();
        for(int i = 1; i < s.size(); i++) {
            char c = s[i];
            if (c == prev) {
                curCount++;
                if(curCount <= prevCount) {
                    res++;
                }
            } else {
                prevCount = curCount;
                curCount = 1;
                res++;
            }
            prev = c;

        }
        return res;
    }
};