class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        struct digit {
            int num;
            int digitSum;
            int ogI;
            bool operator< (const digit& other) const {
                if(other.digitSum < digitSum){
                    return false;
                }
                
                if(other.digitSum > digitSum){
                    return true;
                }
                
                return other.num > num;
            }
            bool operator!= (const digit &other) const {
    
                
                if(other.num != num){
                    return true;
                }
                if(other.digitSum != digitSum) {
                    
                    return true;
                }
                return false;
            }
        };
        
        vector<digit> digits;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int sum = digitSum(num);
            
            digits.push_back({
                .num = num,
                .digitSum = sum,
                .ogI = i,
            });
        }
    
        
        int swaps = 0;
        
        sort(digits.begin(), digits.end());

        //work backwords from the sorted array and find out how many swaps we need to get to the original.

        for(int i = 0; i < digits.size(); i++){
            while(digits[i].ogI != i){
                swaps++;
                swap(digits[i], digits[digits[i].ogI]);
            }
        }
        
        return swaps;
        
    }
    
    
    int digitSum(int i) const {
        int total = 0;
        while( i > 0 ) {
            int digit = i % 10;
            total += digit;
            i /= 10;
        }
        return total;
    }
};