class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;

        for(const auto & num : nums1){
            set1.insert(num);
        }
        for(const auto & num : nums2){
            set2.insert(num);
        }
        vector<int> res;

        unordered_set<int> &larger = set2.size() > set1.size() ? set2 : set1;
        unordered_set<int> &smaller = set2.size() > set1.size() ? set1 : set2;
        for(const auto & num : larger){
            if(smaller.find(num) != smaller.end()){
                res.push_back(num);
            }
        }


        return res;

    }
};