class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> count;
        for(const int num : nums) {
            count[num]++;
        }

        sort(nums.begin(), nums.end(), [&count](int a, int b) {
            if(count[a] < count[b]) {
                return true;
            }
            if(count[a] > count[b]) {
                return false;
            }

            return a > b;
        });

        return nums;
    }
};