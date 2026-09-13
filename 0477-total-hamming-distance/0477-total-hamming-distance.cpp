class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        array<int, 32> arr;
        arr.fill(0);
        int total = 0;
        for(const int num : nums) {
            for(int i = 0; i < 32; i++) {
                int cur = num & (1<<i);
                if(cur > 0) {
                    arr[i]++;
                }
            }
        }

        for(int i = 0; i < 32; i++) {
            int count = arr[i];
            int otherCount = nums.size() - count;
            total += count * otherCount;
        }
        return total;
    }
};