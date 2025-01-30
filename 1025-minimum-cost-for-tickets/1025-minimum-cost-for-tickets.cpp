class Solution {
private:
    vector<int> days;
    vector<int> costs;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->days = days;
        unordered_map<int, int> cache;
        this->costs = costs;
        return dfs(0, 0, cache);
    }
    int dfs(int ticketUntil, int dayIdx, unordered_map<int, int>& cache){
        if(dayIdx >= days.size()){
            return 0;
        }
        if(days[dayIdx] < ticketUntil){
            return dfs(ticketUntil, dayIdx + 1, cache);
        }
        if(cache.find(dayIdx) != cache.end()){
            return cache[dayIdx];
        }
        int i = dayIdx;
        int option1 = dfs(days[dayIdx] + 1, i + 1, cache) + costs[0];
        int option2 = dfs(days[dayIdx] + 7, i + 1, cache) + costs[1];
        int option3 = dfs(days[dayIdx] + 30, i + 1, cache) + costs[2];


        cache[dayIdx] = min({option1, option2, option3});
        return min({option1, option2, option3});    
    }
};