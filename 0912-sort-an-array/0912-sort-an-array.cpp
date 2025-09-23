class Solution {
public:
    static int maxDig(vector<int>& nums) {
        int high = 0;
        for(const int num : nums) {
            if(num == 0) {
                continue;
            }
            int leadingZs = __builtin_clz(num);
            int numDigits = 32 - leadingZs;
            high = max(high, numDigits);
        }
        return high;
    }
    vector<int> sortArray(vector<int>& nums) {       
        int small = *min_element(nums.begin(), nums.end());
        int offset = -small;
        for(auto & num : nums) {
            num += offset;
        } 
        for(int i = 0; i < maxDig(nums); i++){
            digSort(nums, i);
        }
        for(auto & num : nums) {
            num -= offset;
        }
        return nums;
    }

    static void digSort(vector<int>& nums, int d) {
        vector<vector<int>> c(2);
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int dig = (num >> d) % 2;
            c[dig].push_back(num);
        }

        int i = 0;
        for(int j = 0; j <= 1; j++) {
            for(int k = 0; k < c[j].size(); k++) {
                nums[i] = c[j][k];
                i++;
            }
        }
    }
};