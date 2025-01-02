class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        int maxCount = INT_MIN;

        for(const int num : nums){
            count[num]++;
            maxCount = max(maxCount, count[num]);
        }

        std::vector<std::vector<int>> buckets(maxCount + 1);

        for(const auto & p : count){
            buckets[p.second].push_back(p.first);
        }

        std::vector<int> res(k);

        int bucketIndex = buckets.size() - 1;
        for(int i = 0; i < k; i++){
            while(buckets[bucketIndex].empty()){
                bucketIndex--;
            }
            res[i] = (buckets[bucketIndex].back());
            buckets[bucketIndex].pop_back();
        }
        return res;
    }
};