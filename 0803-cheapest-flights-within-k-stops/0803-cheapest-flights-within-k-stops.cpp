class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //bellman ford.
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for(int i = 0; i <= k; i++){
            vector<int> tmpPrices = dist;
            for(const auto & flight : flights){
                int src = flight[0];
                int dst = flight[1];
                int weight = flight[2];

                if(dist[src] == INT_MAX){
                    continue;
                }

                if(dist[src] + weight < tmpPrices[dst]){
                    tmpPrices[dst] = dist[src] + weight;
                }
            }

            dist = tmpPrices;

        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];

    }
};