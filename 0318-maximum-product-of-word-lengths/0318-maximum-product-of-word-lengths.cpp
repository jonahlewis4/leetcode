class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<unordered_set<char>> chars(words.size());
        for(int i = 0; i < words.size(); i++) {
            string& s = words[i];
            unordered_set<char>& set = chars[i];
            for(const char c : s) {
                set.insert(c);
            }
        }

        int pairs = 0;
        int best = 0;
        for(int i = 0; i < words.size(); i++) {
            for(int j = 1; j < words.size(); j++){
                unordered_set<char>& letters1 = chars[i];
                unordered_set<char>& letters2 = chars[j];
                bool match = true;
                
                for(const char c : letters1) {
                    if(letters2.contains(c)) {
                        match = false;
                        break;
                    }
                }

                if(match) {
                    for(const char c : letters2) {
                        if(letters1.contains(c)) {
                            match = false;
                            break;
                        }
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