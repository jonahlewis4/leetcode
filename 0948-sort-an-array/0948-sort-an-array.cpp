class Solution {
private:
    
public:
    vector<int> sortArray(vector<int>& nums) {
        for(int size = 1; size <= nums.size(); size *= 2){
            int sub1 = 0;
            int sub2 = sub1 + size;

            int sub1End = sub1 + size - 1;
            int sub2End = sub2 + size - 1;


            while(sub1 < nums.size()){
                if(sub1End >= nums.size()){
                    sub1End = nums.size() - 1;
                }
                if(sub2End >= nums.size()){
                    sub2End = nums.size() - 1;
                }
                int sub1Size = sub1End - sub1 + 1;
                int sub2Size = max(0, sub2End - sub2 + 1);
                vector<int> merged(sub1Size + sub2Size);

                int mergeI = 0;
                int l = sub1;
                int r = sub2;
                while(l <= sub1End || r <= sub2End) {
                    if(l > sub1End){
                        merged[mergeI] = nums[r];
                        r++;
                    } else if (r > sub2End) {
                        merged[mergeI] = nums[l];
                        l++;
                    } else if (nums[l] < nums[r]){
                        merged[mergeI] = nums[l];
                        l++;
                    } else {
                        merged[mergeI] = nums[r];
                        r++;
                    }
                    mergeI++;
                }

                for(int i = 0; i < merged.size(); i++){
                    nums[sub1 + i] = merged[i];
                }

                sub1 += size * 2;
                sub2 += size * 2;
                sub1End += size * 2;
                sub2End += size * 2;
            }
        }
        return nums;
    }
};