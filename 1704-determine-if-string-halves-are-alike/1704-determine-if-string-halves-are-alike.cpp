class Solution {
private:
    static bool isvowel(const char c) {
        static unordered_set<char> vows = {
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

        return vows.contains(c);
    }
public:
    bool halvesAreAlike(const string& s) const {
        int firstCount = 0;
        int secondCount = 0;
        for(int i = 0; i < s.size(); i++){
            
            char c = s[i];
            if(isvowel(c)){
                bool inFirstHalfOfString = i < s.size() / 2;
                if(inFirstHalfOfString) {
                    firstCount++;
                } else {
                    secondCount++;
                }
            }
        }

        return firstCount == secondCount;
    }
};