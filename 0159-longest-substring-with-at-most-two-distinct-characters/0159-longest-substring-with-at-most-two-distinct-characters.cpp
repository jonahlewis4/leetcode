class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0;
        int r = 0;

        unordered_map<char, int> count;
        for(const char c : s) {
            if(count.size() == 2){
                break;
            }
            count[c]++;
            r++;
        }

        int best = 0;
        while(r < s.size()) {
            char newC = s[r];
            if(count.size() < 2 || count.contains(newC)){
                count[newC]++;
                r++;
            } else {
                best = max(best, r - l);
                while(count.size() == 2) {
                    char lChar = s[l];
                    count[lChar]--;
                    l++;
                    if(count[lChar] == 0){
                        count.erase(lChar);
                    }
                }
            }
        }

        best = max(best, r - l);
        return best;
    }
};