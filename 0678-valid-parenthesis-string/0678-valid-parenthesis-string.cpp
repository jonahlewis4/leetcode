class Solution {
public:
    bool checkValidString(string s) {
        int maxOpen = 0;
        int minOpen = 0;
        for(const char c : s) {
            switch (c) {
                case '(': {
                    maxOpen++;
                    minOpen++;
                    break;
                }
                case ')': {
                    maxOpen--;
                    minOpen--;
                    break;
                }
                case '*': {
                    maxOpen++;
                    minOpen--;
                }
            }

            if(maxOpen < 0) {
                return false;
            }
            if(minOpen < 0) {
                minOpen = 0;
            }
        }

        return minOpen == 0;
    }
};