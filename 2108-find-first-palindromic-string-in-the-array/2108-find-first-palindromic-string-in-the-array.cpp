class Solution {
    static bool isPal(const string& s) {
        for(int i = 0; i < s.size() / 2; i++) {
            int end = s.size() - i - 1;
            if(s[i] != s[end]) {
                return false;
            }
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(const string& s : words) {
            if(isPal(s)) {
                return s;
            }
        }
        return "";
    }
};