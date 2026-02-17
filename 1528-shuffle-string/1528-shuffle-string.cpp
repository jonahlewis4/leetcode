class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res(s.size(), '.');
        for(int i = 0; i < s.size(); i++) {
            int idx = indices[i];
            res[idx] = s[i];
        }

        return res;
    }
};