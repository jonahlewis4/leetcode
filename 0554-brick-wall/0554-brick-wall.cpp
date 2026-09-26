class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<long long, int> sweep;
        bool all1s = true;
        for(const vector<int>& row : wall) {
            long long sum = 0;
            for(const int brick : row) {
                long long start = sum + 1;
                sum += brick;
                long long end = sum - 1;
                sweep[start]++;
                sweep[end+1]--;
            }
            if(row.size() != 1) {
                all1s=false;
            }
        }
        if(all1s) {
            return wall.size();
        }
        int sum = 0;

        long long rowLen = accumulate(wall.front().begin(), wall.front().end(), 0l);
        int least = INT_MAX;
        for(const auto&[key, value] : sweep) {
            if(key == rowLen){
                continue;
            }
            int num = value;
            sum += num;
            least = min(least, sum);
        }
        return least;
    }
};