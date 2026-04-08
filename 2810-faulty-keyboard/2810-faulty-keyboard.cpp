class Solution {
public:
    string finalString(const string& s) {
        string res;
        for(const char c : s) {
            if(c == 'i'){
                reverse(res.begin(), res.end());
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};