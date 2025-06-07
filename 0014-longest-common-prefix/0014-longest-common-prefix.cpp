class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        string res;
        while(true){
            bool noMatch = false;
            bool end = false;
            for(const auto & s : strs) {
                if(i >= s.size() || s[i] != strs[0][i]){
                    noMatch = true;
                    break;
                }
            }
            if(noMatch) {
                return res;
            } else {
                res += strs[0][i];
            }
            i++;
        }
        return res;
    }
};