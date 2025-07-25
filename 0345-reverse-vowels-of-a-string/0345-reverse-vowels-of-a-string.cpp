class Solution {
private:
    static bool isVowel(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
            default:
                return false;
        }
    }
public:
    string reverseVowels(string s) {
        

        

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