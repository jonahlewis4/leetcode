class Solution {
private:
    static unordered_set<char> vowels;
public:
    bool isValid(string word) {
        if(word.size() < 3) {
            return false;
        }
        bool containsVowel = false;
        bool containsConsonant = false;

        for(const auto & c : word) {
            if(isalpha(c)) {
                if(vowels.find(c) != vowels.end()) {
                    containsVowel = true;
                } else {
                    containsConsonant = true;
                }
            } else if (!isdigit(c)) {
                return false;
            }
        }
        return containsVowel && containsConsonant;

    }
};
unordered_set<char> Solution::vowels = {
    'a',
    'e',
    'i',
    'o',
    'u',
    'A',
    'E',
    'I',
    'O',
    'U',
};