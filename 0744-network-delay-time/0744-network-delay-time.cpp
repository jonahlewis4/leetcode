class Solution {
    struct edge{
        int dest;
        int weight;
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //MST.

        //djiksta's ant return the max.
        //if one of them is INT_MAX return -1;

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<edge, vector<edge>, decltype([](const auto & a, const auto & b){
            return a.weight > b.weight;
        })> pq; 

        pq.push({
            .dest = k,
            .weight = 0
        });

        vector<vector<edge>> adjList(n + 1);
        for(const auto & time : times){
            adjList[time[0]].push_back({
                .dest = time[1],
                .weight = time[2],
            });
        }

        while(!pq.empty()){
            edge e = pq.top();
            pq.pop();
            if(e.weight > dist[e.dest]){
                continue;
            }
            for(const auto & neigh : adjList[e.dest]){
                int newWeight = neigh.weight + e.weight;
                if(newWeight < dist[neigh.dest]){
                    dist[neigh.dest] = newWeight;
                    pq.push({
                        .dest = neigh.dest,
                        .weight = newWeight
                    });
                }
            }
        }

        int maxi = INT_MIN;
        for(int i = 1; i < dist.size(); i++){
            if(dist[i] == INT_MAX){
                return -1;
            } 
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};