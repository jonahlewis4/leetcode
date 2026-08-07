class Solution {
    static int scan(const string& s, int k, int numAllowedChars) {
        unordered_map<char, int> count;
        int l = 0;
        int r = 0;
        int longest = 0;
        int meeting = 0;
        while(r < s.size()) {
            char newChar = s[r];
            count[newChar]++;
            if(count[newChar] == k) {
                meeting++;
            }
            while(count.size() > numAllowedChars) {
                char lChar = s[l];
                count[lChar]--;
                if(count[lChar] == k - 1) {
                    meeting--;
                }
                if(count[lChar] == 0) {
                    count.erase(lChar);
                }
                l++;        
            }

            if(count.size() == meeting) {
                int length = r - l + 1;
                longest = max(length, longest);
            }

            r++;
        }

        return longest;
    }
public:
    int longestSubstring(string s, int k) {
        int best = 0;
        for(int i = 26; i >= 1; i--) {
            int attempt = scan(s, k, i);
            best = max(best, attempt);
        }

        return best;
    }
};