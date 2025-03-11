class Solution {
public:
    int findTheLongestSubstring(string s) {
        std::unordered_map<char, int> val = {
            {'a', 1},
            {'e', 2},
            {'i', 4},
            {'o', 8},
            {'u', 16}
        };
        int mask = 0;
        unordered_map<int, int> hits;
        int maxLen = 0;
        for(int i = 0;i < s.size(); i++){
            char c = s[i];
            int value = val[c];
            if(value != 0){
                mask ^= value;
            }
            if(hits.find(mask) == hits.end()){
                hits[mask] = i;
            }
            if(mask == 0){
                maxLen = max(maxLen, i + 1);
            }
            maxLen = max(maxLen, i - hits[mask]);

        }
        return maxLen;
    }
};