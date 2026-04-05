class Solution {
public:
    string makeSmallestPalindrome(string s) {
        for(int i = 0; i < s.size() / 2; i++) {
            int end = s.size() - i - 1;
            if(s[i] != s[end]) {
                char smaller = min(s[i], s[end]);
                s[i] = smaller;
                s[end] = smaller;
            }
        }

        return s;
    }
};