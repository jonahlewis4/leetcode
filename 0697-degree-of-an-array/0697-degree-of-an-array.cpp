class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        unordered_map<int, queue<int>> first;

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
            first[num].push(i);
        }

        



        freq = {};
        int minLen = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            int newNum = nums[i];
            freq[newNum]++;
            if(freq[newNum] >= maxFreq){
                int len = i - first[newNum].front() + 1;
                minLen = min(len, minLen);
                first[newNum].pop();
            }
        }

        return minLen;
    }
};