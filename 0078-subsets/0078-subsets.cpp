class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        unordered_map<int, bool> available;
        for(auto itr = nums.begin(); itr != nums.end(); itr++){
            available[*itr] = true;
        }
        findSubsets({}, subsets, available);
        subsets.push_back({});
        return subsets;
    }
    void findSubsets(vector<int> subset, vector<vector<int>> &subsets, unordered_map<int, bool> available)   
    {
        for(auto itr = available.begin(); itr != available.end();){
            int num = itr->first;
            subset.push_back(num);
            subsets.push_back(subset);
            itr = available.erase(itr);
            findSubsets(subset, subsets, available);
            subset.pop_back();
        }
    }
};