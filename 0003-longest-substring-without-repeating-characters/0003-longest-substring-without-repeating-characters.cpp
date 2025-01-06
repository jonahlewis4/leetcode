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

        while(r < s.size()){
            //longest = max(longest, r - l );
            if(map.find(s[r]) == map.end()){
                map[s[r]] = r;
            } else {
                int newL = (map[s[r]]) + 1;
                if(longest < r - l){
                }
                longest = max(longest, r - l);

                while(l < newL){
                    if(l < newL  - 1){
                        map.erase(map[s[l]]);
                    }
                    l++;
                }
                map[s[r]] = r;
            }
            r++;
        }
        longest = max(longest, r - l );

        return longest;
    }
};