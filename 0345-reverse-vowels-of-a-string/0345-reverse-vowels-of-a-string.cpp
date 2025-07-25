class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {
            'a',
            'e',
            'i',
            'o',
            'u',
        };

        const auto & isVowel = [&vowels](char c) {
            char lower = tolower(c);
            return vowels.find(lower) != vowels.end();
        };

        int l = 0;
        int r = s.size() - 1;
        while(l <  r) {
            while(l < r && !isVowel(s[l])){
                l++;
            }
            while(r > l && !isVowel(s[r])){
                r--;
            }
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};