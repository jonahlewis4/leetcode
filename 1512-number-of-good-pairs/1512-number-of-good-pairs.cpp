class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> c(101, 0);
        int pairs = 0;
        for(const int i : nums) {
            pairs += c[i];
            c[i]++;
        }
        return pairs;
    }
};