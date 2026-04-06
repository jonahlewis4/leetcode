class Solution {
public:
    string makeGood(string s) {
        string res;
        for(const char c : s) {
            if(res.empty()) {
                res.push_back(c);
                continue;
            }

            char back = res.back();
            if(back != c && tolower(back) == tolower(c)) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};