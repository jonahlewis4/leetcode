class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int maxElem = *max_element(nums.begin(), nums.end());
        vector<int> count(maxElem + 1, 0);

        for(const int num : nums) {
            count[num]++;
        }

        int l = 0;
        int r = count.size() - 1;

        for(int i = 0; i < nums.size(); i+=2) {
            while(count[l] == 0) {
                l++;
            }
            while(count[r] == 0 && r > l) {
                r--;
            }

            nums[i] = l;
            if(i + 1 < nums.size()) {
                nums[i + 1] = r;
            }
            count[l]--;
            count[r]--;
        }
    }
};