class Solution {
private:
    struct edgeDest{
        int node;
        int weight;
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<edgeDest>> adjList;
        for(const auto & time : times){
            int node1 = time[0];
            int node2 = time[1];
            int weight = time[2];
            adjList[node1].push_back({
                .node = node2,
                .weight = weight
            });
        }  

        auto cmp = [](const auto & a, const auto & b){
            return a.weight > b.weight;
        };
        priority_queue<edgeDest, vector<edgeDest>, decltype(cmp)> pq;

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({
            .node = k,
            .weight = 0
        });

        vector<int> visited(n + 1, false);
        int vc = 0;
        while(!pq.empty() && vc < n){
            edgeDest e = pq.top();
            pq.pop();

            if(visited[e.node]){
                continue;
            }
            visited[e.node] = true;
            vc++;

            for(auto const & neigh : adjList[e.node]){
                int newWeight = neigh.weight + e.weight;

                if(!visited[neigh.node] && newWeight < dist[neigh.node]){
                    dist[neigh.node] = newWeight;
                    pq.push({
                        .node = neigh.node,
                        .weight = newWeight
                    });
                }
            }
        }



        int res = -1;
        for(int i = 1; i < dist.size(); i++){
            res = max(res, dist[i]);
        }

        return res == INT_MAX ? -1 : res;
    }
};