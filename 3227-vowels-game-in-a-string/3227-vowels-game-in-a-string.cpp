class Solution {
    static bool isVowel(const char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    bool doesAliceWin(string s) {
        int vCount = 0;
        for(const char c : s) {
            if(isVowel(c)){
                vCount++;
            }
        }

        return vCount > 0;
    }
};