class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        struct difSet {
            string hashKey;
            difSet(const string& s){
                //populate difs
                char firstChar = s.front() - 'a';
                for(const char c : s){
                    int aDist = c - 'a';
                    int equalizer = aDist - firstChar;
                    equalizer = (equalizer + 26) % 26; 
                    hashKey += equalizer;
                    hashKey += ".";
                }
            }
        };

        unordered_map<difSet, vector<string>, decltype([](const difSet& set){
            return std::hash<string>()(set.hashKey);
        }), decltype([](const difSet& a, const difSet& b){return a.hashKey == b.hashKey;})> map;

        for(const string& s : strings){
            difSet dSet(s);
            map[dSet].push_back(s);
        }

        vector<vector<string>> ans;
        for(const auto & [_, stringVec] : map){
            ans.push_back(stringVec);
        }
        
        return ans;
    }
};