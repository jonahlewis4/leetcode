// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    static int rand10() {
        int total = 0;
        for(int i = 0; i < 5; i++) {
            int sub = rand7() - 1;
            total += sub;
        }
        return total % 10 + 1;
    }
};