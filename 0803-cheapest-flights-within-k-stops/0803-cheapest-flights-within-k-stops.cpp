class Solution {
    struct edge{
        int dest;
        int weight;  
    };
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //bfs of edges. 
        //check if we've reached this dst in less time. Since we're going time by time
        //we can guarantee each change will only be beneficial. 

        vector<vector<edge>> adjList(n);
        for(const auto & flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            adjList[from].push_back({
                .dest = to,
                .weight = price
            });
        }

        queue<edge> q;
        q.push({
            .dest = src,
            .weight = 0
        });

        vector<int> distance(n, INT_MAX);
        distance[src] = 0;

        int stops = 0;
        while(!q.empty()){
            if(stops > k){
                break;
            }
            int n = q.size();
            vector<int> nextDistances = distance;
            for(int i  = 0; i < n; i++){
                edge e = q.front();
                q.pop();
                if(e.weight < distance[e.dest]){
                    continue;
                }
                
                for(const auto & n : adjList[e.dest]){
                    int newWeight = n.weight + e.weight;
                    if(newWeight < nextDistances[n.dest]){
                        nextDistances[n.dest] = newWeight;
                        q.push({
                            .dest = n.dest,
                            .weight = newWeight
                        });
                    }
                    
                }
            }
            distance = nextDistances;
            stops++;
        }
        
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};