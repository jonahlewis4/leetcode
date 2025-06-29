class Solution {
public:
    vector<int> grayCode(int n) {
        n = 1 << n;
        vector<int> nums(n, -1);
        int i = 0;
        int last = 0;
        unordered_set<int> visited;
        while(i < n - 1) {
            nums[i] = last;
            visited.insert(last);

            int copy = last;
            
            for(int j = 0; j < n; j++) {
                int power = 1 << j;
                int digit = copy % 2;
                copy /= 2;
                int modified;
                if(digit == 0) {
                    modified = last | power;
                } else {
                    modified = last ^ power;
                }
                if(visited.count(modified) == 0) {
                    last = modified;
                    break;
                }
            }

            i++;
        }
        nums[i] = last;
        return nums;
    }
};