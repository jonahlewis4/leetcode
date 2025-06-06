class Solution {
public:
    string lastSubstring(string s) {
        int l = 0;
        int r = 1;
        int k = 0;

        while(r + k < s.size()) {
            if(s[l + k] == s[r + k]){
                k++;
            } else if (s[l + k] < s[r + k]){
                l = max(r, l + k + 1);
                r = l + 1;
                k = 0;
            } else {
                r = r + k + 1;
                k = 0;
            }
        }

        return s.substr(l, s.size() - l);
    }
};