class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> keys;
        unordered_map<char, string> map;
        vector<string> words = split(s, ' ');

        if(words.size() != pattern.size()) {
            return false;
        }

        for(int i = 0; i < pattern.size(); i++){
            char c = pattern[i];
            const string& word = words[i];

            const auto itr = map.find(c);
            if(itr == map.end()) {
                if(keys.find(word) != keys.end()) {
                    return false;
                }
                map[c] = word;
                keys[word] = c;
                continue;
            } else {
                const string& extant = itr->second;
                if(extant != word) {
                    return false;
                }
            }
        }
        return true;
    }

    vector<string> split(const string&s, const char delim) {
        vector<string> res;
        if(s.size() == 0) {
            return {};
        }
        string cur = "";
        for(const char c : s) {
            if(c == delim) {
                if(cur.size() > 0) {
                    res.push_back(cur);
                    cur = "";
                }
            } else {
                cur += c;
            }
        }
        if(cur.size() > 0) {
            res.push_back(cur);
        }

        return res;
    }
};