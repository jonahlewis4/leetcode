class Solution {
    class Recursive{
        const vector<int> &nums;
        int recurse(int n, int total){
            if(n >= nums.size()){
                return total;
            } else {
                //else skip this house and rob the next one
                int skip = recurse(n + 1, total);

                //or rob this house and skip the next one.
                int rob = recurse(n + 2, total + nums[n]);

                return max(skip, rob);
            }   
        }
    public:
        Recursive(const vector<int> &_nums) : nums(_nums) {}
        int Solution(){
            return recurse(0, 0);
        }
    };

    class Memo {
        const vector<int> &nums;
        vector<int> cache;
    private: 
        int recurse(int i){
            if(cache[i] != -1){
                return cache[i];
            }
            int skip = recurse(i + 1);
            int rob = nums[i] + recurse(i + 2);
            int res = max(skip, rob);
            cache[i] = res;
            return res;
        }
    public:
        Memo(const vector<int> &_nums) : nums(_nums){
            cache.resize(_nums.size() + 2, -1);
            cache[_nums.size()] = 0;
            cache[_nums.size() + 1] = 0;
        }
        int Solution() {
            return recurse(0);
        }
    };

public:
    int rob(vector<int>& nums) {
        return Memo(nums).Solution();
    }
    
};