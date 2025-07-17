class Solution {
public:
    int hammingDistance(int x, int y) {
        const auto & xSet = bitset<32>(x);
        const auto & ySet = bitset<32>(y);
        int diff = 0;
        for(int i = 0; i < xSet.size(); i++) {
            if(xSet[i] != ySet[i]){
                diff++;
            }
        }
        return diff;
    }
};