class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        if(k == 1) {
            return 'a';
        }
        for(int i = 0; i < k; i++) {
            int n = s.size();
            for(int j = 0; j < n; j++) {
                s += s[j] + 1;
                if(k-1 < s.size()) {
                    return s[k-1];
                }
            }
        }
        return ' ';
    }
};