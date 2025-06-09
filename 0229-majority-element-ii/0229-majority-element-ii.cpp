class Solution {
    template <typename T>
    int countIn(const vector<T> & nums, T i) const {
        int count = 0 ;
        for(const auto & num : nums) {
            if(num == i) {
                count++;
            }
        }
        return count;
    }
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = nums[0];
        int c1Count = 1;
        int c2;
        int c2Count = 0;

        for(int i = 1; i < nums.size(); i++){
            if((c2Count != 0 && nums[i] != c2 && c1Count == 0) || nums[i] == c1){
                if(c1Count == 0){
                    c1 = nums[i];
                }
                c1Count++;
            } else if (c2Count == 0 || nums[i] == c2){
                if(c2Count == 0){
                    c2 = nums[i];
                }
                c2Count++;
            } else {
                c1Count--;
                c2Count--;
            }
        }

        //determine count of c1 and c2
        vector<int> res;
        if(c1Count != 0){
            if(countIn(nums, c1) > nums.size() / 3) {
                res.push_back(c1);
            }
        }

        if(c2Count != 0){
            if(countIn(nums, c2) > nums.size() / 3) {
                res.push_back(c2);
            }
        }
        return res;
    }
};