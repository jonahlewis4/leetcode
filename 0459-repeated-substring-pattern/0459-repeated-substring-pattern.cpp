class Solution {
public:
    bool repeatedSubstringPattern(const string& s) {
        int find = (s+s).find(s, 1);
        return find < s.size();
    }
};