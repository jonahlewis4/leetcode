class Solution {
public:
    int countCommas(int n) {
        int commas = 0;
        if(n >= 1000) {
            commas += n - 999;
        }

        return commas;
        
    }
};