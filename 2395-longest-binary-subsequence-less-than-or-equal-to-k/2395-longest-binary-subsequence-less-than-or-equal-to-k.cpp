class Solution {
public:
    int longestSubsequence(string s, int k) {
        int num = 0;
        int len = 0;
        int bits = 32 - __builtin_clz(k);
        for(int i = 0; i < s.size(); i++){
            char c = s[s.size() - 1 - i];
            if(c == '1'){
                if(i < bits && num + (1 << i) <= k){
                    num += 1 << i;
                    len++;
                }
            } else {
                len++;
            }
        }
        return len;
    }
};