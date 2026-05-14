class Solution {
public:
    string modifyString(string s) {
        if(s.front() == '?') {
            s.front() = 'a';
            if(s.size() > 1 && s[1] == 'a') {
                s.front() = 'b';
            }
        }

        if(s.back() == '?') {
            s.back() = 'a';
            if(s.size() > 1 && s[s.size() - 2] == 'a') {
                s.back() = 'b';
            }
        }
        for(int i = 1; i + 1 < s.size(); i++) {
            if(s[i] == '?') {
                s[i] = 'a';
                if(s[i - 1] == 'a' || s[i + 1] == 'a') {
                    s[i] = 'b';
                    if(s[i - 1] == 'b' || s[i + 1] == 'b') {
                        s[i] = 'c';
                    }
                }
            }
        }
        return s;
    }
};