class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for(const std::string & str : strs){
            std::string key = str;
            std::sort(key.begin(), key.end());
            map[key].push_back(str);
        }

        std::vector<std::vector<std::string>> res(map.size());

        int i = 0;
        for(const auto & group : map){
            res[i] = group.second;
            i++;
        }
        return res;
    }
};