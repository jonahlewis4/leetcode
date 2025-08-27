class Solution {
public:
    int minOperations(int n) {
        auto bset = bitset<17>(n);
        int moves = 0;
        for(int i = 0; i < bset.size(); i++) {
            if(bset[i] == 1) {
                if(i == bset.size() - 1) {
                    if(bset[i - 1] == 0) {
                        moves++;
                        continue;
                    }
                    moves += 2;
                } else if(bset[i + 1] == 0) {
                    if(i == 0 || bset[i - 1] == 0) {
                        moves++;
                        continue;
                    }
                    int j = i;
                    while(j >= 0 && bset[j] == 1) {
                        bset[j] = 0;
                        j--;
                    }
                    moves++;
                    bset[i + 1] = 1;
                }
            }
        }
        return moves;
    }
};