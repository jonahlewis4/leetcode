class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int bottom = grid.size() - 1;
        int left = 0;
        
        int sum = 0;
        while(bottom >= 0){
            while(left < grid.front().size() && grid[bottom][left] >= 0) {
                left++;
            }

            int remaining = grid.front().size() - left;
            sum += remaining;

            bottom--;
        }

        return sum;

    }
};