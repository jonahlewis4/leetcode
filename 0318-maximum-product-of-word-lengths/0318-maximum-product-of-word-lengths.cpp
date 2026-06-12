class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<string> chars;
        chars.reserve(words.size());
        for(const string& s : words) {
            unordered_set<char> set;
            for(const char c : s) {
                set.insert(c);
            }
            string letters(26, '.');
            for(const char c : set) {
                letters[c - 'a'] = 'y';
            }
            chars.push_back(letters);
        }

        int pairs = 0;
        int best = 0;
        for(int i = 0; i < words.size(); i++) {
            for(int j = 1; j < words.size(); j++){
                string& letters1 = chars[i];
                string& letters2 = chars[j];
                bool match = true;
                for(int i = 0; i < 26; i++) {
                    if(letters1[i] == letters2[i] && letters1[i] == 'y') {
                        match = false;
                        break;
                    }
                }

                if(match) {
                    int product = words[i].size() * words[j].size();
                    best = max(best, product);
                }
            }
        }
        return best;
    }
};