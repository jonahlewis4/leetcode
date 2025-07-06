class FindSumPairs {
    unordered_map<int, int> freq1;
    unordered_map<int, int> freq2;
    vector<int>& nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums2(nums2) {
        for(const auto & num : nums1) {
            freq1[num]++;
        }
        for(const auto & num : nums2) {
            freq2[num]++;
        }
    }
    
    void add(int index, int val) {
        int num = nums2[index];
        freq2[num] = freq2[num] - 1;
        int newNum = num + val;
        freq2[newNum]++;
        nums2[index] = newNum;
        
    }
    
    int count(int tot) {
        //optimization: use size of freq1 or freq2 to dettermine which to 
        //iterate over
        int ans = 0;
        for(const auto & keyValPair : freq1) {
            int occur1 = keyValPair.second;
            int num = keyValPair.first;
            if(freq2.find(tot - num) == freq2.end()) {
                continue;
            }
            int occur2 = freq2[tot - num];
            ans += occur1 * occur2;
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */