class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        const auto & cmp = [](const vector<int>& a, const vector<int>& b) {
            int sum1 = a.front() + a.back();
            int sum2 = b.front() + b.back();
            return sum1 <= sum2;
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                vector<int> pair = {nums1[i], nums2[j]};
                if(pq.size() == k && cmp(pq.top(), pair)){
                    break;
                }
                if(pq.size() < k || cmp(pair, pq.top())){
                    pq.push(pair);
                }
                if(pq.size() > k) {
                    pq.pop();
                }
            }
        }


        vector<vector<int>> res;
        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};