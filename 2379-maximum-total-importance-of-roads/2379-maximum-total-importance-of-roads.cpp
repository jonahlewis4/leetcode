class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegrees(n);
        for(auto const & road : roads){
            int src = road[0];
            int dest = road[1];
            indegrees[src]++;
            indegrees[dest]++;
        }
        sort(indegrees.begin(), indegrees.end());

        long long sum = 0;

        int i = 1;
        for(auto const & degree : indegrees){
            sum += (long long)degree * i;
            i++;
        }

        return sum;


    }
};