class Solution {
public:
    int countGoodSubstrings(string s) {
        char first = s.front();
        char second = s[1];
        int good = 0;
        for(int i = 2; i < s.size(); i++) {
            char third = s[i];
            if(first != second && second != third && first != third) {
                good++;
            }
            first = second;
            second = third;
        }

        return good;
    }
};