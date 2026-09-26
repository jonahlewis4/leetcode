class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        vector<pair<long long, int>> sweep;
        
        bool all1 = true;
        for(const vector<int>& row : wall) {
            
            long long sum = 0;
            for(const int brick : row) {
                long long start = sum + 1;
                sum += brick;
                long long end = sum - 1;
                sweep.push_back({start, 1});
                sweep.push_back({end + 1, -1});
            }
            if(row.size() != 1) {
                all1 = false;
            }
        }

        if(all1) {
            return wall.size();
        }
        long long sum = 0;

        sort(sweep.begin(), sweep.end(), [](const pair<long long, int>& a, const pair<long long, int>& b) {
            if(a.first < b.first) {
                return true;
            }
            if(a.first > b.first) {
                return false;
            }
            return a.second > b.second;
        });

        long long least = INT_MAX;
        int prevStamp = sweep.front().first;
        for(const pair<long long, int>& event : sweep) {
            //cout<<"event: "<<event.front()<<"|"<<event.back()<<endl;
            int stamp = event.first;
            if(stamp != prevStamp) {
                //cout<<sum<<endl;
                least = min(least, sum);
            }
            int num = event.second;
            sum += num;
            prevStamp = stamp;
        }
        //least = min(least, sum);
        return least;
    }
};