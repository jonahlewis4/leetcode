class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        vector<vector<long long>> sweep;
        
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

        sort(sweep.begin(), sweep.end(), [](const vector<long long>& a, const vector<long long>& b) {
            if(a.front() < b.front()) {
                return true;
            }
            if(a.front() > b.front()) {
                return false;
            }
            return a.back() > b.back();
        });

        long long least = INT_MAX;
        int prevStamp = sweep.front().front();
        for(const vector<long long> event : sweep) {
            //cout<<"event: "<<event.front()<<"|"<<event.back()<<endl;
            int stamp = event.front();
            if(stamp != prevStamp) {
                cout<<sum<<endl;
                least = min(least, sum);
            }
            int num = event.back();
            sum += num;
            prevStamp = stamp;
        }
        //least = min(least, sum);
        return least;
    }
};