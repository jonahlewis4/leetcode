class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency;

        for(const auto & num : nums){
            frequency[num]++;
        }

        int maxCount = INT_MIN;
        for(const auto & keyVal : frequency){
            maxCount = std::max(maxCount, keyVal.second);
        }

        std::vector<vector<int>> count(maxCount, vector<int>(0));

        for(const auto & keyVal : frequency) {
            count[keyVal.second - 1].push_back(keyVal.first);
        }

        std::vector<int> res(k);

        int countIndex = count.size() - 1;
        for(int i = 0; i < k; i++){
            while(count[countIndex].empty()){
                countIndex--;
            }
            res[i] = count[countIndex].back();
            count[countIndex].pop_back();
        }
        return res;
    
    }
};