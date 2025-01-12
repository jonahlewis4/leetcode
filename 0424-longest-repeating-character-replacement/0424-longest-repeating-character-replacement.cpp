class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> counts;
        int longest = INT_MIN;

        int l = 0;
        int r = 0;
        int maxChar = 0;
        while(r < s.size()){
            counts[s[r]]++;
            maxChar = max(maxChar, counts[s[r]]);
            while(maxChar + k < r - l + 1){
                counts[s[l]]--;
                l++;
            } 
            r++;
        }
        return maxChar + k <= s.size() ? maxChar + k : s.size();
    }
};