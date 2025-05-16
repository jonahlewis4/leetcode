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

class Recursive{
public:
    int lengthOfLIS(vector<int>& nums) const {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res = max(res, recurse(i, nums));
        }
        return res;
    }

    int recurse(int i, const vector<int>& nums) const{
        if(i == 0){
            return 1;
        }       


        int res = 1;
        for(int j = i - 1; j >= 0; j--){
            if(nums[j] < nums[i]){
                int largestFromJ = recurse(j, nums);
                res = max(res, largestFromJ + 1);
            } 
        }
        return res;
    }

};

class Memo{
    vector<int> cache;
public:
    int lengthOfLIS(vector<int>& nums) {
        cache.resize(nums.size(), -1);
        
        for(int i = 0; i < nums.size(); i++){
            recurse(i, nums);
        }

        return *max_element(cache.begin(), cache.end());
    }

    int recurse(int i, const vector<int>& nums) {
        if(i == 0){
            cache[i] = 1;
            return cache[i];
        }       

        if(cache[i] != -1){
            return cache[i];
        }

        int res = 1;
        for(int j = i - 1; j >= 0; j--){
            if(nums[j] < nums[i]){
                int largestFromJ = recurse(j, nums);
                res = max(res, largestFromJ + 1);
            } 
        }
        cache[i] = res;
        return cache[i];
    }
};

class Solution {
    public:
    int lengthOfLIS(vector<int>& nums) {
        return Memo().lengthOfLIS(nums);
    }
};