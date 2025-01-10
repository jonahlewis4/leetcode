class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num0s = 0;
        int num1s = 0;
        int num2s = 0;

        for(const int num : nums){
            switch (num) {
                case 0: {
                    num0s++;
                    break;
                }
                case 1: {
                    num1s++;
                    break;
                }
                case 2: {
                    num2s++;
                    break;
                }
            }
        }    

        int i = 0;
        for(int j = 0; j < num0s; j++){
            nums[i] = 0;
            i++;
        }
        for(int j = 0; j < num1s; j++){
            nums[i] = 1;
            i++;
        }
        for(int j = 0; j < num2s; j++){
            nums[i] = 2;
            i++;
        }
    }
};