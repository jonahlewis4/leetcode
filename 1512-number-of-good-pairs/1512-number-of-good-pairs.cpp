class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> c;
        int pairs = 0;
        for(const int i : nums) {
            pairs += c[i];
            c[i]++;
        }
        return pairs;
    }
};