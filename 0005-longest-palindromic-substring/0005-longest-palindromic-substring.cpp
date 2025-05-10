class Solution {
public:
    string longestPalindrome(const string &s) {
        int oL = 0;
        int oR = 0;

        for(int i = 0; i < s.size(); i++){
            const auto [l, r] = calc(i, i, s);

            int len = r - l + 1;
            if(len > oR - oL + 1){
                oR = r;
                oL = l;
            } 
        }

        for(int i = 0; i + 1 < s.size(); i++){
            const auto [l, r] = calc(i, i + 1, s);
            int len = r - l + 1;
            if(len > oR - oL + 1){
                oR = r;
                oL = l;
            }
        }

        return s.substr(oL, oR - oL + 1);
    }
    tuple<int, int> calc(int l, int r, const string &s) const {
        int oldL = 0;
        int oldR = 0;
        while(l >= 0 && r < s.size()){
            if(s[l] != s[r]){
                return {oldL, oldR};
            }
            oldL = l;
            oldR = r;

            l--;
            r++;
        }
        return {oldL, oldR};
    }
};