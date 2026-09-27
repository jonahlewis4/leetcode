class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(const int num : nums) {
            map[num]++;
        }

        int pairs = 0;
        for(const auto& [num, count] : map) {
            int comp1 = k + num;
            int comp2 = num - k;

            if(num == comp1){
                if(count != 1) {
                    pairs++;
                }
                continue;
            }

            
            if(num < comp1 && map.contains(comp1)) {
                pairs++;
            }
            if(num < comp2 && map.contains(comp2)) {
                pairs++;
            }



          
        }
        return pairs;
    }
};