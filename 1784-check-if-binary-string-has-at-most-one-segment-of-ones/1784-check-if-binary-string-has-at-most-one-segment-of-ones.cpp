class Solution {
public:
    bool checkOnesSegment(string s) {
        bool oneFound = false;
        char prev = '1';
        for(const char c : s) {

            if(c == '1' && oneFound && prev != '1'){
                return false;
            }

            if(c == '1') {
                oneFound = true;
            }

            prev = c;

        }

        return true;
    }
};