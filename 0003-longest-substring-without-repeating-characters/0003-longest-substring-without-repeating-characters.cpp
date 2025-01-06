class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }
        
        std::unordered_map<char, int> map;
        int l = 0;
        int r = 0;

        int longest = 0;

        while (r < s.size()){
            char c = s[r];
            if(map.find(c) != map.end() && map[c] >= l){
                l = map[c] + 1;
            }
            longest = std::max(r - l + 1, longest);
            map[c] = r;
            r++;
        } 
        return longest;
    }
};