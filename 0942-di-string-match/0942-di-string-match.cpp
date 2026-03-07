class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> res(s.size() + 1, 0);
        int r = s.size();
        int l = 0;

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == 'I') {
                res[i] = l++;
            } else {
                res[i] = r--;
            }
        }

        res.back() = r;
        return res;
    }
};