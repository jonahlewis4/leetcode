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
        unordered_map<char, int> vowels;

        string sortedVowel = "AEIOUaeiou";
        

        for(const auto &  c : s) {
            if(isVowel(c)) {
                vowels[c]++;
            }
        }
        int sortI = 0;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(isVowel(c)) {
                while(vowels[sortedVowel[sortI]] == 0) {
                    sortI++;
                }

                s[i] = sortedVowel[sortI];
                vowels[sortedVowel[sortI]]--;
            }
        }

        return s;
    }
};