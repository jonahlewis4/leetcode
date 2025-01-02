class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency;

        for(const auto & num : nums){
            frequency[num]++;
        }
        
        std::priority_queue<pair<int, int>> pq;
        for(const auto & keyVal : frequency){
            pq.push({keyVal.second, keyVal.first});
        }   

        std::vector<int> res(k);
        for(int i = 0; i < k; i++){
            res[i] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};