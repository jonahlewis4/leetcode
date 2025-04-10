class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dst(n + 1, INT_MAX);

        vector<vector<pair<int, int>>> adjList(n + 1);
        for(const auto & time : times){
            int node1 = time[0];
            int node2 = time[1];
            int weight = time[2];

            adjList[node1].push_back({weight, node2});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<bool> visited(n + 1, false);
        dst[k] = 0;
        int visitCount = 0;
        int ans = -1;
        while(!pq.empty()){
            auto [weight, node] = pq.top();
            pq.pop();
            if(visited[node]){
                continue;
            }

            visited[node] = true;
            visitCount++;

            ans = weight;

            for(const auto & neigh : adjList[node]){
                auto [neighWeight, neighNode] = neigh;
                
                int newWeight = weight + neighWeight;
                //dst[neighNode] = newWeight;
                if(!visited[neighNode]){
                    pq.push({
                        newWeight,
                        neighNode
                    });
                }
            }
        }
        return visitCount == n ? ans : -1;

    }
};