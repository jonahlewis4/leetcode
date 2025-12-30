class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> res(26, INT_MAX);
        for(const string& word : words) {
            vector<int> in(26, 0);
            for(const char c : word) {
                in[c - 'a']++;
            }

            for(int i = 0; i < 26; i++) {
                res[i] = min(res[i],in[i]);
            }
        }

        vector<string> fin;
        for(int i = 0; i < res.size(); i++) {
            for(int j = 0; j < res[i]; j++) {
                fin.push_back(string(1, (i + 'a')));
            }
        }

        return fin;
    }
};