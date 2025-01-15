class Solution {
private:
    int pivot;
    vector<int> *nms;
    int get(int i){
        return nms->at((i + pivot )%nms->size() );
    }
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int pivot = 0;
        while(l <= r){
            int m = (l + r) / 2;
            int mVal = nums[m];
            int rIdx = m + 1 < nums.size() ? m + 1 : 0;
            int rVal = nums[rIdx];
            if(mVal == target){
                return m;
            }
            if(rVal == target){
                return rIdx;
            }

            if(mVal > nums[0] && rVal <= nums[0]){
                pivot = rIdx;
                break;
            } else if (mVal > nums[0]){
                l = m + 1;
            } else {
                r = m - 1;
            }
            
        }

        l = 0;
        r = nums.size();

        this->nms = &nums;
        this->pivot = pivot;

        while(l <= r){
            int m = (l + r) / 2;

            if(get(m) == target){
                return (m + pivot) % nums.size();
            }
            if(get(m) < target){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }



        return -1;
    }
};