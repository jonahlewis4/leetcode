class Solution {
private:
    //T is a random access iterator
    void mergesort(int l, int r, vector<int>& nums){
        if(l == r){
            return;
        }  

        int m = (l + r) / 2;
        mergesort(l, m, nums);
        mergesort(m + 1, r, nums);

        vector<int> merged(r - l + 1);
        int mergeI = 0;

        int rightI = m + 1;
        int leftI = l;

        while(leftI <= m || rightI <= r){
            if(leftI > m){
                merged[mergeI] = nums[rightI];
                rightI++;
            } else if(rightI > r){
                merged[mergeI] = nums[leftI];
                leftI++;
            } else if (nums[leftI] <= nums[rightI]){
                merged[mergeI] = nums[leftI];
                leftI++;
            } else {
                merged[mergeI] = nums[rightI];
                rightI++;
            }
            mergeI++;
        }

        int ogI = l;
        for(int i = 0; i < merged.size(); i++){
            nums[ogI] = merged[i];
            ogI++;
        }



    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(0, nums.size() - 1, nums);
        return nums;
    }
};