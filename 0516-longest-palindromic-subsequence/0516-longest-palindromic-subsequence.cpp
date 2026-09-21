class Solution {
    int calc(int l, int r, const string& s) {
        if(l > r) {
            return 0;
        }
        if(l == r) {
            return 1;
        }

        if(cache[l][r] != -1) {
            return cache[l][r];
        }
        if(s[l] == s[r]) {
            int res = 2 + calc(l+1, r-1, s);
            cache[l][r] = res;
            return res;
        }
        int optL = calc(l+1, r, s);
        int optR = calc(l, r-1, s);
        
        int res = max(optL, optR);
        cache[l][r] = res;
        return res;
    }
    vector<vector<int>> cache;
public:
    int longestPalindromeSubseq(string s) {
        cache.resize(s.size(), vector<int>(s.size(), -1));
        return calc(0, s.size() - 1, s);
    }
};