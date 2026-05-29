class Solution {
public:
    string reverseOnlyLetters(string s) {
        string letters;
        for(const char c : s) {
            if(isalpha(c)){
                letters += c;
            }
        }
        reverse(letters.begin(), letters.end());
        int i = 0;
        for(char& c : s) {
            if(isalpha(c)){
                c = letters[i];
                i++;
            }
        }
        return s;
    }
};