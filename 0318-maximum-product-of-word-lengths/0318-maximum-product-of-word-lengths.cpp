class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<unsigned int> chars(words.size());
        for(int i = 0; i < words.size(); i++) {
            string& s = words[i];
            unsigned int& set = chars[i];
            for(const char c : s) {
                int numeric = c - 'a';
                int mask = 1 << numeric;
                set |= mask;
            }
        }

        int pairs = 0;
        int best = 0;
        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++){
                unsigned int& letters1 = chars[i];
                unsigned int& letters2 = chars[j];
                bool match = (letters1 & letters2) == 0;
                if(match) {
                    int product = words[i].size() * words[j].size();
                    best = max(best, product);
                }
            }
        }
        return best;
    }
};