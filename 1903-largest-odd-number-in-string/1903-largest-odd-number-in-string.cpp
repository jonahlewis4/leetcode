class Solution {
public:
    string largestOddNumber(string num) {
        int r = num.size() - 1;
        while(r >= 0 && (num[r] - '0') % 2 == 0) {
            r--;
        }

        if(r == -1) {
            return "";
        }

        return num.substr(0, r + 1);
    }
};