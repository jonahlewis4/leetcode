class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        string res;
        while(true){
            for(const auto & s : strs) {
                if(i >= s.size() || s[i] != strs[0][i]){
                    return res;
                }
            }
            
            res += strs[0][i];
            
            i++;
        }
        return res;
    }
};