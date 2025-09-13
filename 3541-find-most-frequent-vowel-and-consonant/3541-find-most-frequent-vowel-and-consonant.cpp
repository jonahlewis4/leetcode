class Solution {
    static bool isVowel(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            return true;
        }
        return false;
    }
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> cs;
        unordered_map<char, int> vs;

        int maxC = 0;
        int maxV = 0;

        for(const char c : s) {
            if(isVowel(c)){
                maxV = max(maxV, ++vs[c]);
            } else {
                maxC = max(maxC, ++cs[c]);
            }
        }

        return maxC + maxV;
    }
};