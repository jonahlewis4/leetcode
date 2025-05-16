class LowerBound{
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;

        sub.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            //find first number >= num.
            auto lb = low_bound(sub.begin(), sub.end(), num);

            //if at the end push it back
            if(lb == sub.end()){
                sub.push_back(num);
            } else /*otherwise replace the one at that position with that value */ {
                int index = lb - sub.begin();
                sub[index] = num;
            }
        }

        return sub.size();
    }

    template <typename T>
    vector<T>::iterator low_bound(const vector<T>::iterator begin, const vector<T>::iterator end, T target) const{
        int l = begin - begin;
        int r = end - 1 - begin;

        auto smallest = end;
        while(l <= r) {
            int m = (l + r) / 2;
            auto midItr = begin + m;
            T midElement = *midItr;

            if(midElement >= target){
                if (smallest == end){
                    smallest = midItr;
                } else if(midElement < *smallest){
                    smallest = midItr;
                }
                r = m - 1;
            } else /*if midElement is smaller than the target, we need to visit larger value*/ {
                l = m + 1;
            }
        }
        return smallest;
    }
    
};

class Solution {
    public:
    int lengthOfLIS(vector<int>& nums) {
        return LowerBound().lengthOfLIS(nums);
    }
};