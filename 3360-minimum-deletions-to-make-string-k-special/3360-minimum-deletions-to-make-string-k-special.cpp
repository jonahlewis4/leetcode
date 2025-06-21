class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for(const auto & c : word){
            freq[c]++;
        }

        int best = INT_MAX;
        for(const auto & [_, count] : freq){
            int removals = 0;
            for(const auto & [_, count2] : freq) {
                if(count2 < count) {
                    removals += count2;
                } else if (count2 > count + k) {
                    removals += count2 - (count + k);
                }
            }
            best = min(best, removals);
        }
        return best;
    }
};