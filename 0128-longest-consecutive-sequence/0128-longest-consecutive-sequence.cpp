class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set;
        for(const auto & num : nums){
            set.insert(num);
        }

        int longest = 0;
        for(const auto & num : set){
            if(set.find(num - 1) == set.end()){
                int length = 1;
                while(set.find(num + length) != set.end()){
                    length++;
                }
                longest = std::max(length, longest);
            }
        }
        return longest;
    }
};