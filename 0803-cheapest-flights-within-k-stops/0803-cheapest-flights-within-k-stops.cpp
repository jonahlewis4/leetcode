class Solution {
    struct visit {
        int id;
        int weight;
    };

    struct edge {
        int nextId;
        int weight;
    };

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //basic queue.  

        vector<vector<edge>> adjList(n);
        for(const auto & flight : flights){
            int src = flight[0];
            int dst = flight[1];
            int weight = flight[2];
            adjList[src].push_back({
                .nextId = dst,
                .weight = weight
            });
        }
        
        queue<visit> q;
        q.push({
            .id = src,
            .weight = 0
        });

        vector<int> distances(n, INT_MAX);


        int i = 0;
        while(!q.empty() && i <= k + 1){
            int n = q.size();
            for(int j = 0; j < n; j++){
                auto v = q.front();
                q.pop();
                if(v.weight > distances[v.id]){
                    continue;
                }
                distances[v.id] = v.weight;

                for(const auto & edge : adjList[v.id]){
                    int newWeight = v.weight + edge.weight;
                    if(newWeight <= distances[edge.nextId]){
                        q.push({
                            .id = edge.nextId,
                            .weight = newWeight
                        });
                    }
                }
            }
            i++;
        }

        return distances[dst] == INT_MAX ? -1 : distances[dst];
    }
};