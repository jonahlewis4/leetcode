class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int total = 0;
        for(const char c : s) {
            switch (c) {
                case 'R':
                    count++;
                    break;
                case 'L':
                    count--;
                    break;
            }
            if(count == 0) {
                total++;
            }
        }

        return total;

    }
};