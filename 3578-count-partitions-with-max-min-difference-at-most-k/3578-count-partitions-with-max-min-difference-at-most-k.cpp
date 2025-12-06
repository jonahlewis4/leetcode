class Solution {
    class MinMax {
        deque<int> maxVal;
        deque<int> minVal;
    public:
        int diff() const {
            return maxVal.front() - minVal.front();
        }

        void add(int i) {
            while(!minVal.empty() 
            && minVal.back() > i) {
                minVal.pop_back();
            }

            minVal.push_back(i);

            while(!maxVal.empty()
                && maxVal.back() < i
            ){
                maxVal.pop_back();
            }

            maxVal.push_back(i);
        }

        void dec(int i) {
            if(!minVal.empty() && minVal.front() == i) {
                minVal.pop_front();
            }

            if(!maxVal.empty() && maxVal.front() == i) {
                maxVal.pop_front();
            }
        }
    };                  
public:                
    int countPartitions(vector<int>& nums, int k) {
        vector<int> sum(nums.size() + 2, 0);
        
        int mod = (int)(1e9) + 7;

        sum[nums.size() - 1] = 1;
        MinMax mm;
        mm.add(nums.back());

        int r = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--) {
            mm.add(nums[i]);
            int diff = mm.diff();
            if(diff > k) {
                while(mm.diff() > k){
                    mm.dec(nums[r]);
                    r--;
                }

                long long next = sum[i + 1] - sum[r + 2];
                sum[i] = (sum[i+1] + next)%mod;
            } else {
                long long next = ((sum[i + 1] - sum[i + 2])*2)%mod;
                sum[i] = (sum[i+1] + next)%mod;
            }
        }
        
        int total = sum.front();
        int one = *next(sum.begin());
        int res = ((total - one)%mod + mod)%mod;
        return res;
    }
};