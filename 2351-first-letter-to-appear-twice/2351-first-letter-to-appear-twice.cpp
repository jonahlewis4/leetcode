class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> set;
        for(const char c : s) {
            if(set.contains(c)) {
                return c;
            }
            set.insert(c);
        }

        return s.back();
    }
};