class Solution {
public:
    int longestPalindrome(string s) {
        int pairs = 0;
        unordered_set<int> set;
        for(const char c : s) { 
            if(set.contains(c)) {
                pairs++;
                set.erase(c);
            } else {
                set.insert(c);
            }
        }

        return pairs * 2 + (set.empty() ? 0 : 1);
    }
};