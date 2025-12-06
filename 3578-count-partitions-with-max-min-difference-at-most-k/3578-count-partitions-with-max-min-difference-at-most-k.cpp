class Solution {
    class MinMax {
    public:
        multiset<int> set;
        int diff() const {
            if(set.size() == 1 || set.size() == 0) {
                return 0;
            }

            int min = *set.begin();
            int end = *prev(set.end());

            return end - min;
        }

        void add(int i) {
            set.insert(i);
        }

        void dec(int i) {
            auto itr = set.find(i);
            set.erase(itr);
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