class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int letter = coordinates[0] - 'a';
        int number = coordinates[1] - '1';

        if(letter % 2 == 0 && number % 2 == 0) {
            return false;
        } else if (letter % 2 == 0 && number % 2 == 1) {
            return true;
        } else if (letter % 2 == 1 && number % 2 == 0) {
            return true;
        } else {
            return false;
        }
    }
};