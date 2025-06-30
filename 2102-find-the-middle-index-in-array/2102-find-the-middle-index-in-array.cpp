class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        unordered_map<int, int> sumsWhichCouldSatisfy;
        int leftSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int sumWhichCouldSatisfy = leftSum * 2 + num;
            if(sumsWhichCouldSatisfy.find(sumWhichCouldSatisfy) == sumsWhichCouldSatisfy.end()) {
                sumsWhichCouldSatisfy[sumWhichCouldSatisfy] = i;
            }
            leftSum += num;
        }
        if(sumsWhichCouldSatisfy.find(leftSum) == sumsWhichCouldSatisfy.end()) {
            return -1;
        }
        return sumsWhichCouldSatisfy[leftSum];
    }
};