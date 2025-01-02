class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set;
        for(const int num : nums){
            if(set.find(num) == set.end()) set.insert(num);
        }

        int maxLong = 0;
        for(const int i : set){
            if(set.find(i - 1) == set.end()){
                int length = 1;
                while(set.find(i + length) != set.end()){
                    length++;
                }
                maxLong = max(maxLong, length);
            }
        }
        return maxLong;
    }
};