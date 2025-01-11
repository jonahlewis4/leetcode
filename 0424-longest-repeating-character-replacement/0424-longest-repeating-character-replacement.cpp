class Solution {
public:
    int characterReplacement(string s, int k) {
       
        std::unordered_map<char, int> counts;

        int l = 0;
        int r = 0;
        int maxLen = 0;
        int maxChar = 0;
        while(r < s.size()){
            counts[s[r]]++;
            maxChar = max(maxChar, counts[s[r]]);
            if(maxChar + k < r - l + 1){
                counts[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};