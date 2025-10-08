class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> count;
        if(s.size() < 11){
            return {};
        }

        string cur = "";
        for(int i = 0; i < 10; i++) {
            cur += s[i];
        }

        count[cur]++;

        for(int i = 10; i < s.size(); i++) {
            char c = s[i];
            cur += c;
            cur = cur.substr(1);

            count[cur]++;
        }

        vector<string> res;
        for(const auto & [key, count] : count) {
            if(count > 1) {
                res.push_back(key);
            }
        }
        return res;
    }
};