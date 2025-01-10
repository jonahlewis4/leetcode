class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int l = 0; 
        int r = 0;
        std::deque<int> dq;
        vector<int> res(nums.size() - k + 1);
        while(r < k){
            while(!dq.empty() && nums[dq.back()] < nums[r]){
                dq.pop_back();
            }
            dq.push_back({r});
            r++;
        }

        for(int i = 0; i < res.size(); i++){
            while(!dq.empty() && dq.front() < l){
                dq.pop_front();
            }
            res[i] = nums[dq.front()];
            l++;


            if(r < nums.size()){
                while(!dq.empty() && nums[dq.back()] < nums[r]){
                    dq.pop_back();
                }

                dq.push_back(r);
            }
            r++;
        }
        return res;


    }
};