class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       std::deque<int> dq;

       int l = 0;
       int r = 0;


        int windowCount = nums.size() - k + 1;
        std::vector<int> ans;
        while(r < nums.size()){
            while(!dq.empty() && nums[dq.back()] < nums[r]){
                dq.pop_back();
            }  
            dq.push_back(r);

            while(!dq.empty() && dq.front() < l){
                dq.pop_front();
            }

            if(r >= k - 1){
                ans.push_back(nums[dq.front()]);
                l++;
            }           
            r++;
        } 
        return ans;
    }
};