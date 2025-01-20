class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for(int i = 0; i < s.size(); i++){
            res ^= s[i];
            res ^= t[i];
        }
        return res ^ t[t.size() - 1];
    }
};