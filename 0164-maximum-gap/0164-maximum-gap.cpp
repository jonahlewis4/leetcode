class Solution {
    class RadixSort {
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
    static void sortArray(vector<int>& nums) {       
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
    }

    static void digSort(vector<int>& nums, int d) {
        vector<vector<int>> c(2);
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int dig = (num >> d) & 1;
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
public:
    int maximumGap(vector<int>& nums) {
        
        if(nums.size() == 1) {
            return 0;
        }
        RadixSort::sortArray(nums);
        int best = 0;
        for(int i = 1; i < nums.size(); i++) {
            int delta = nums[i] - nums[i - 1];
            best = max(delta, best);
        }
        return best;

    }

    void countSort(vector<int> &nums) {
        unordered_map<int ,int> count;
        for(const int num : nums) {
            count[num]++;
        }

        int resI = 0;
        for(int i = 0; i <= *(max_element(nums.begin(), nums.end())); i++) {
            if(!count.contains(i)) {
                continue;
            }
            for(int j = 0; j < count[i]; j++){
                nums[resI] = i;
                resI++;
            }
        }
    }
};