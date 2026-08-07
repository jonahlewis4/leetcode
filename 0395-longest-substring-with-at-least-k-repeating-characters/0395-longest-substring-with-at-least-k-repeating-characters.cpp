class Solution {
    static bool scan(const string& s, int k, int windowSize) {
        unordered_map<char, int> count;
        int meeting = 0;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            count[c]++;
            if(count[c] == k) {
                meeting++;
            }

            if(i + 1 >= windowSize) {
                if(meeting == count.size()) {
                    return true;
                }

                char lC = s[i - windowSize + 1];
                count[lC]--;
                if(count[lC] == k - 1) {
                    meeting--;
                }
                if(count[lC] == 0) {
                    count.erase(lC);
                }
            }
        }

        return false;
    }
public:
    int longestSubstring(string s, int k) {
        for(int i = s.size(); i >= k; i--) {
            bool attempt = scan(s, k, i);
            if(attempt){
                return i;
            }
        }

        return 0;
    }
};