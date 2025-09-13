class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(const int i : nums) {
            count[i]++;
        }

        for(int i : nums) {
            //go left till left is 0
            int ogI = i;
            while(count[i - 1] != 0) {
                i--;
            }

            //crawlcheck til back at value and empty
            while(count[ogI] != 0) {
                while(count[i] != 0) {
                    for(int j = i; j < i + k; j++) {
                        if(count[j]-- == 0){
                            return false;
                        }
                    }
                }
                i++;

            }
        }

        return true;
    }
};