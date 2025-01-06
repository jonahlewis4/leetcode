class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> count;

        int l = 0;
        int r = 0;

        int maxCount = 0;
        while(r < s.size()){
            count[s[r]]++;
            maxCount = max(maxCount, count[s[r]]);
            int len = r - l + 1;
            if(len - maxCount > k){
                count[s[l]]--;
                l++;
            }
            r++;
        }
        return std::min(maxCount + k, (int)s.size());
    }
};