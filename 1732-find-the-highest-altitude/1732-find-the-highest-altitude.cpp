class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int best = 0;
        int amt = 0;
        for(const int g : gain) {
            amt += g;
            best = max(best, amt);
        }

        return best;
    }
};