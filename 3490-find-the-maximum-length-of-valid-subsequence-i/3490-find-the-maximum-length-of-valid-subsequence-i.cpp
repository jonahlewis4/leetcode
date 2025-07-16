class Solution {
private:
    static bool isEven(int num) {
        return num % 2 == 0;
    }
public:
    int maximumLength(vector<int>& nums) {
        int oddCount = 0;
        int evenCount = 0;
        int switches = 1;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            bool curParity = isEven(num);
            
            if(curParity){
                evenCount++;
            } else {
                oddCount++;
            }

            if(i >= 1) {
                int previous = nums[i - 1];
                bool lastParity = isEven(previous);
                if(lastParity != curParity) {
                    switches++;
                }
            }
        }
        return max ({oddCount, evenCount, switches});
    }
};