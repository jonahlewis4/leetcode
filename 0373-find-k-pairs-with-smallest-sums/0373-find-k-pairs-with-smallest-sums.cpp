class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        const auto & cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            int sum1 = a.first + a.second;
            int sum2 = b.first + b.second;
            return sum1 <= sum2;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                pair<int, int> pair = {nums1[i], nums2[j]};
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
            res.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};