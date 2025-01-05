class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1; 

        int find = -1;

        while(l <= r){
            int m = (l + r) / 2;

            if(nums[m] == target){
                find = m;
                break;
            } else if (nums[m] < target){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        if(find == -1){
            return {-1, -1};
        }
        

        int lBound = target;

        l = 0;
        r = find;   

        if(nums[l] == target){
            lBound = 0;
        } else{
            while(l <= r){
                int m = (l + r) / 2;
                lBound = m + 1;
                if(m + 1 < nums.size() && nums[m] < target && nums[m + 1] == target){
                    break;
                } else if (nums[m] == target){
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }

        
        

        int rBound = target;
        l = find;
        r = nums.size() - 1;

        if(nums[r] == target){
            rBound = nums.size() - 1;
        } else{
            while(l <= r){
                int m = (l + r) / 2;
                rBound = m - 1;
                if(m - 1 >= 0 && nums[m] > target && nums[m - 1] == target){
                    break;
                } else if (nums[m] == target){
                    l = m + 1;
                } else {
                    r = m - 1;
                }   
            }
        }
        
       

        return {lBound, rBound};

    }
};