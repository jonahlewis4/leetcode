class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        //calculate target
        int target = 0;
        for(const int num : nums){
            target += num;
            target %= p;
        }
        if(target == 0){
            return 0;
        }

        //find a subarray where the mod is target. This is what we'll delete.

        //7 2 5 2     ::   target = 7. p = 9
        //7 0 5 7


        //1 3 3 1     ::   target = 8 % 3 = 2
        //1 1 1 2


        //6 3 5 2     ::        target = 16 % 9 = 7 
        //6 0 5 7.    ::
        
        unordered_map<int, int> rightmost;
        int min = nums.size();
        
        int curMod = 0;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            curMod += num;
            curMod %= p;
            
            rightmost[curMod] = i;

            //we want to find a prev such that (cur - prev) % p == target 
            if(curMod == target){
                min = std::min(min, i + 1);
            }
            int prevMod = (curMod - target + p) % p;
            if(rightmost.find(prevMod) != rightmost.end()){
                int prevIdx = rightmost[prevMod];
                min = std::min(i - prevIdx, min);
            }
        }

        if(min == nums.size()){
            return -1;
        }
        return min;

    }
};