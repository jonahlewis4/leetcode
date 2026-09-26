class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> sweep;
        for(const vector<int>& row : wall) {
            long long sum = 0;
            for(int i = 0; i < row.size() - 1; i++) {
                int brick  = row[i];
                sum += brick;
                long long end = sum;
                sweep[end]++;
            }
        }

        int least = 0;
        for(const auto& [key, value] : sweep) {
            least = max(least, value);
        }
        return wall.size()-least;
        
    }
};