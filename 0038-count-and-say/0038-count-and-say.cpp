class Solution {
public:
    string countAndSay(int n) {
        string s = "0";
        string prev = "";
        for(int i = 1; i <= n; i++){
            if(i == 1){
                prev = "1";
            } else {
                prev = rle(prev);
            }
        }
        return prev;
    }

    string rle(const string &s) const {
        if(s == ""){
            return "";
        }
        string res = "";
        char lastChar = '.';
        int streakCount = 0;
        for(int i = 0; i < s.size(); i++){
            if(i >= 1 && s[i] != s[i - 1]){
                res += to_string(streakCount);
                res += s[i - 1];
                streakCount = 1;
            } else {
                streakCount++;
            }
        }
        res += to_string(streakCount);
        res += s[s.size() - 1];
        return res;
    }
};