class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<pair<int, int>> descend(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            descend[i] = {nums[i], i};
        }
        sort(descend.begin(), descend.end(), greater<>());
        set<int> avail;
        vector<int> res(nums.size());
        vector<int> updates;
        for(int i = 0; i < descend.size(); i++) {
            if(i > 0 && descend[i].first < descend[i - 1].first) {
                while(!updates.empty()) {
                    avail.insert(updates.back());
                    updates.pop_back();
                }
            }
            int num = descend[i].first;
            int idx = descend[i].second;

            //search for one after idx in avail
            set<int>::iterator itr = avail.upper_bound(idx);
            if(itr != avail.end()) {
                int ansIdx = *itr;
                res[idx] = nums[ansIdx];
            } else {
                if(!avail.empty()) {
                    int ansIdx = *avail.begin();
                    res[idx] = nums[ansIdx];
                } else {
                    res[idx] = -1;
                }
            }

            updates.push_back(idx);
        }

        return res;
    }
};