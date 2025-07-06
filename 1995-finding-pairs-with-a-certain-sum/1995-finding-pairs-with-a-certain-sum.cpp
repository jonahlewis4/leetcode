class FindSumPairs {
    unordered_map<int, int> freq2;
    vector<int>& nums2;
    vector<int>& nums1;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for(const auto & num : nums2) {
            freq2[num]++;
        }
    }
    
    void add(int index, int val) {
        int num = nums2[index];
        freq2[num]--;
        int newNum = num + val;
        freq2[newNum]++;
        nums2[index] = newNum;
        
    }
    
    int count(int tot) {
        //optimization: use size of freq1 or freq2 to dettermine which to 
        //iterate over
        int ans = 0;
        for(const auto & num : nums1) {
            int occur = freq2[tot - num];
            ans += max(0, occur);
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