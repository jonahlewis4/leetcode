class Solution {
    struct edge{
        int src;
        int dest;
        int weight;
    };
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        vector<edge> edges;
        for(auto const & flight : flights){
            int src = flight[0];
            int to = flight[1];
            int price = flight[2];
            edges.push_back({
                .src = src,
                .dest = to,
                .weight = price,
            });
        }

        //k + 1 because we want to see which node we can reach after k + 1 # of edges (stops does not count the final edge)
        for(int i = 0; i < k + 1; i++){
            vector<int> newDist = dist;
            for(const auto & e : edges){
                if(dist[e.src] == INT_MAX){
                    continue;
                }
                if(dist[e.src] + e.weight < newDist[e.dest]){
                    newDist[e.dest] = dist[e.src] + e.weight;
                }
            }
            dist = newDist;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
        
    }
};