class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        struct Num {
            int val;
            int ogI;
        };

        priority_queue<Num, vector<Num>, decltype([](const auto & a, const auto & b){
            //return true if lower prio
            return a.val > b.val;
        })> pq;

        for(int i = 0; i < nums.size(); i++) {
            if(pq.size() < k) {
                pq.push({
                    .val = nums[i],
                    .ogI = i,
                });
            } else if (pq.top().val < nums[i]){
                pq.pop();
                pq.push({
                    .val = nums[i],
                    .ogI = i,
                });
            }
        }

        vector<Num> res(k);
        int i = 0;
        while(!pq.empty()){
            res[i] = pq.top();
            pq.pop(); 
            i++;
        }

        sort(res.begin(), res.end(), [](const auto & a, const auto & b) {
            return a.ogI < b.ogI;
        });

        vector<int> ans(k);
        for(int i = 0; i < ans.size(); i++) {
            ans[i] = res[i].val;
        }
        return ans;
    }
};