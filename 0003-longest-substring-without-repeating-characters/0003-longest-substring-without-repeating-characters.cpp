class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        std::unordered_set<char> set;

        int l = 0; 
        int r = 0;

        int maxLen = 0;
        while(r < s.size()){
            while(set.find(s[r]) != set.end()){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            r++;



            maxLen = max(maxLen, r - l);
        }
        return maxLen;

    }
};