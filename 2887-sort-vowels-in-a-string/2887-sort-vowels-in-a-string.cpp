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
        priority_queue<char, vector<char>, greater<char>> vowels;

        for(const auto &  c : s) {
            if(isVowel(c)) {
                vowels.push(c);
            }
        }

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(isVowel(c)) {
                s[i] = vowels.top();
                vowels.pop();
            }
        }

        return s;
    }
};