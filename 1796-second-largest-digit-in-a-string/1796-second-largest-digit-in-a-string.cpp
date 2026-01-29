class Solution {
public:
    int secondHighest(string s) {
        vector<int> dig(10, 0);
        for(const char c : s) {
            if(isdigit(c)){
                int d = c - '0';
                dig[d]++;
            }
            
        }

        bool found = false;
        for(int i = 9; i >= 0; i--) {
            if(dig[i] && !found){
                found = true;
                continue;
            } else if (dig[i]) {
                return i;
            }
        }
        return -1;
    }
};