class Solution {
    static bool isVowel (const char c) {
        char l = tolower(c);
        if(l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u'){
            return true;
        }
        return false;
    }
public:
    string sortVowels(string s) {
        map<char, int> vowels;

        

        for(const auto &  c : s) {
            if(isVowel(c)) {
                vowels[c]++;
            }
        }

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(isVowel(c)) {
                s[i] = vowels.begin()->first;
                vowels.begin()->second--;
                if(vowels.begin()->second == 0){
                    vowels.erase(vowels.begin());
                }
            }
        }

        return s;
    }
};