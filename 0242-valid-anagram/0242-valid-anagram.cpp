class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> sMap;

        for(const auto & c : s){
            sMap[c]++;
        }

        for(const auto & c : t){
            if(sMap.find(c) == sMap.end()){
                return false;
            }
            if(sMap[c] == 1){
                sMap.erase(c);
            }
            else {
                sMap[c]--;
            }
        }
        return sMap.empty();
    }
};