class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> map;
        for(const auto & str : strs){
            string key = str;
            std::sort(key.begin(), key.end());
            map[key].push_back(str);
        }
        std::vector<vector<string>> res;
        for(const auto & group: map){
            res.push_back(group.second);
        }
        return res;
    }
};