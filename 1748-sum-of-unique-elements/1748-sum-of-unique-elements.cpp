class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> map;
        int sum = 0;
        for(const int num : nums) {
            map[num]++;

            if(map[num] == 1) {
                sum += num;
            } else if (map[num] == 2) {
                sum -= num;
            }
        }

        return sum;
    }
};