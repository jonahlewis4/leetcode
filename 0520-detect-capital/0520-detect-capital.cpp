class Solution {
public:
    bool detectCapitalUse(string word) {
        int capCount = 0;
        for(const char c : word) {
            if(tolower(c) != c) {
                capCount++;
            }
        }

        if(capCount == 0) {
            return true;
        }

        if(capCount == word.size()) {
            return true;
        }

        return capCount == 1 && tolower(word.front()) != word.front();
    }
};