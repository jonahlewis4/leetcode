class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            int val = c - 'a';
            int trueVal = 26 - val;
            total += trueVal * (i + 1);
        }

        return total;

    }
};