class Solution {
public:
    bool isBalanced(string num) {
        int imbalance = 0;
        for(int i = 0; i < num.size(); i++) {
            char c = num[i];
            int digit = c - '0';
            if(i % 2 == 0) {
                imbalance += digit;
            } else {
                imbalance -= digit;
            }
        
        }
        return !imbalance; 
    }
};