class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> c;
        int highFre = 0;
        int cFre = 0;
        for(const int num : nums) {
            c[num]++;
            int freq = c[num];
            if(freq == cFre) {
                highFre += freq;
            }
            if(freq > cFre) {
                cFre = freq;
                highFre = freq;
            }
        }
        return highFre;
    }

};