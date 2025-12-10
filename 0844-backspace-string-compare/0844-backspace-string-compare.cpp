class Solution {
    void load(const string& s, string& sRes) {
        for(const char c : s) {
            if(c == '#'){
                if(!sRes.empty()) {
                    sRes.pop_back();
                }
            } else {
                sRes.push_back(c);
            }
        }
    }
public:
    bool backspaceCompare(string s, string t) {
        string sRes;
        string tRes;

        load(s, sRes);
        load(t, tRes);

        return sRes == tRes;
        
    }
};