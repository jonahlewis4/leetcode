class Solution {
private:
    unordered_set<int> setify(const vector<int>& nums) {
        unordered_set<int> set;
        for(const int i : nums) {
            set.insert(i);
        }
        return set;
    }
    void collate(
        unordered_set<int>& src,
        unordered_set<int>& m1,
        unordered_set<int>& m2,
        vector<int>& res
    )    {
        for(auto itr = src.begin(); itr != src.end();){
            int i = *itr;
            if(m1.contains(i) || m2.contains(i)) {
                m1.erase(i);
                m2.erase(i);
                res.push_back(i);
                itr = src.erase(itr);
            } else {
                ++itr;
            }
        }
    }
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        auto s1 = setify(nums1);
        auto s2 = setify(nums2);
        auto s3 = setify(nums3);

        vector<int> res;
        collate(s1, s2, s3, res);
        collate(s2, s1, s3, res);
        collate(s3, s1, s2, res);

        return res;

    }
};