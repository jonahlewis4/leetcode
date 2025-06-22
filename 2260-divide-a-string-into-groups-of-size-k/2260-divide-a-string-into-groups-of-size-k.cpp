class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res((s.size() - 1) / k + 1, string(k, fill));
        for(int i = 0; i < s.size(); i++) {
            int resI = i / k;
            int splitI = i % k;
            res[resI][splitI] = s[i];
        }
        return res;
    }
};