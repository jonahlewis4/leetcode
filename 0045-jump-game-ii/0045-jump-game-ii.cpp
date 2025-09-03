class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) {
            return 0;
        }
        
        queue<int> q;
        vector<bool> enqueued(nums.size() - 1, false);

        q.push(0);
        enqueued[0] = true;
        int jumps = 0;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                int idx = q.front();
                q.pop();

                for(int j = idx + 1; j <= idx + nums[idx] && j < nums.size(); j++){
                    if(j == nums.size() - 1){
                        return jumps + 1;
                    }
                    if(enqueued[j]) {
                        continue;
                    }
                    q.push(j);
                    enqueued[j] = true;
                }
            }
            jumps++;
        }

        return -1;

    }
};