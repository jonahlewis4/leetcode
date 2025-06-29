class Solution {
public:
    vector<int> grayCode(int n) {
        n = 1 << n;
        vector<int> nums(n, -1);
        int i = 0;
        int last = 0;
        vector<bool> visited(n, false);
        while(i < n - 1) {
            nums[i] = last;
            visited[last] = true;

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
                if(visited[modified] == false) {
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