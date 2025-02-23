class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> pq;

        unordered_map<int, int> taskCount;
        for(int task : tasks){
            taskCount[task]++;
        }
        for(const auto & p : taskCount){
            pq.push({p.second, -n - 1});
        }

        std::queue<pair<int, int>> q;

        int intervals = 0;

        while(!pq.empty() || !q.empty()){
            if(!q.empty() && q.front().second + n < intervals){
                if(q.front().first > 0){
                    pq.push({q.front().first, intervals});
                }
                q.pop();
            } else if (!pq.empty()){
                auto p = pq.top();
                pq.pop();
                if(p.first - 1 > 0){
                    q.push({p.first - 1, intervals});
                }
                intervals++;
            } else {
                intervals++;
            }
            
        }
        return intervals;
    }
};