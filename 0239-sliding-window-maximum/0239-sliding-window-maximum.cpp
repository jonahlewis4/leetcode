class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::priority_queue<pair<int, int>> pq;

        int l = 0; 
        int r = 0;

        vector<int> res(nums.size() - k + 1);
        while(r < k){
            pq.push({nums[r], r});
            r++;
        }

        for(int i = 0; i < res.size(); i++){
            while(pq.top().second < l){
                pq.pop();
            }
            res[i] = pq.top().first;
            l++;
            if(r < nums.size()){
                pq.push({nums[r], r});
            }
            r++;
        }
        return res;


    }
};