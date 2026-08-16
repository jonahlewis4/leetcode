class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int best = 0;
        int mask = 0;
        unordered_set<int> set;

        for(int i = 31; i >= 0; i--) {
            mask |= (1<<i);
            for(int num : nums) {
                set.insert(num & mask);
            }

            int bestAttempt = best | (1<<i);

            for(int left : set) {
                int comp = bestAttempt ^ left;
                if(set.contains(comp)) {
                    best = bestAttempt;
                }
            }
            set.clear();
        }
        return best;
    }
};