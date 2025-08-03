class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> in;
        for(const auto & jewel : jewels) {
            in.insert(jewel);
        }
        int match = 0;
        for(const auto & stone : stones) {
            if(in.find(stone) != in.end()) {
                match++;
            }
        }
        return match;
    }
};