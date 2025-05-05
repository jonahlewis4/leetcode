//4 options:

//1. Bellman ford
//2. Djikstra's
//3. BFS

class Solution {
private:
    
    struct Args{
        int n;
        vector<vector<int>> flights;
        int src;
        int dst;
        int k;
    };

    class BellmanFord{
        private:
            const Args &args;
            struct Edge{
                int src;
                int dest;
                int weight;
            };
        public:
            BellmanFord(const Args& _args) : args(_args){} 
            int Solution() {
                //Bellman Ford: loop through all the edges and compute the closest distance for the destination.
                //Do this n + 1 times. 
                //make sure to use a temp array to ensure we don't premptively do further ones. 
                vector<Edge> edges;
                for(auto const &flight : args.flights){
                    int src = flight[0];
                    int dest = flight[1];
                    int weight = flight[2];
                    edges.push_back({
                        .src = src,
                        .dest = dest,
                        .weight = weight,
                    });
                }

                vector<int> dist(args.n, INT_MAX);
                dist[args.src] = 0;
                for(int i = 0; i < args.k + 1; i++){
                    vector<int> newDist = dist;
                    for(const auto & edge : edges){
                        if(dist[edge.src] == INT_MAX){
                            continue;
                        }
                        if(dist[edge.src] + edge.weight < newDist[edge.dest]){
                            newDist[edge.dest] = dist[edge.src] + edge.weight;
                        }
                    }
                    dist = newDist;
                }

                return dist[args.dst] == INT_MAX ? -1 : dist[args.dst];

            }
    };
    class Djikstras{
    private:
        const Args &args;
        struct Stop{
            int dest;
            int weight;
            int stops;

            //return true if this has smaller priority than other
            bool operator<(const Stop &other) const {
                return weight > other.weight;
            }
        };
        struct Edge {
            int dest;
            int weight;
        };
    public:
        Djikstras(const Args &_args) : args(_args){}
        //find the nearest unvisited node
        //if its the end return it
        //if it is within k stops stick with it
        //and check all its neighboors with appropriate distance from it.
        int Solution(){
            vector<vector<int>> dist(args.n, vector<int>(args.k + 2, INT_MAX));
            
            //construct adjacency list.
            vector<vector<Edge>> adjList(args.n);
            for(const auto & flight : args.flights){
                int src = flight[0];
                int dest = flight[1];
                int weight = flight[2];
                adjList[src].push_back({
                    .dest = dest,
                    .weight = weight,
                });
            }


            priority_queue<Stop> pq;
            pq.push({
                .dest = args.src,
                .weight = 0,
                .stops = 0,
            });

            //if k is 1 stop can be 0 or 1 and it's acceptable.
            while(!pq.empty()){
                Stop stop = pq.top();
                pq.pop();
                if(stop.dest == args.dst){
                    return stop.weight;
                }
                if(stop.stops > args.k || stop.weight > dist[stop.dest][stop.stops]){
                    continue;
                }
                for(const auto & neigh : adjList[stop.dest]){
                    int newWeight = neigh.weight + stop.weight;
                    int newStops = stop.stops + 1;

                    if(newWeight < dist[neigh.dest][newStops]){
                        dist[neigh.dest][newStops] = newWeight;
                        pq.push({
                            .dest = neigh.dest,
                            .weight = newWeight,
                            .stops = newStops,
                        });
                    }
                }

            } 
            return -1;
        }
    };
    class BFS {
    private:
        const Args &args;
    public:
        BFS(const Args &_args) : args(_args) {}
        int Solution() const{
        int n = args.n;
        int src = args.src;
        int dst = args.dst;
        const auto & flights = args.flights;
        int k = args.k;
            vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        queue<tuple<int, int, int>> q;
        q.push({0, src, 0});

        while (!q.empty()) {
            auto [cst, node, stops] = q.front();
            q.pop();
            if (stops > k) continue;

            for (const auto& neighbor : adj[node]) {
                int nei = neighbor.first, w = neighbor.second;
                int nextCost = cst + w;
                if (nextCost < prices[nei]) {
                    prices[nei] = nextCost;
                    q.push({nextCost, nei, stops + 1});
                }
            }
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
        

    };
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        Args args;
        args.n = n;
        args.flights = flights;
        args.src = src;
        args.dst = dst;
        args.k = k;
        //return BellmanFord(args).Solution();
        return BFS(args).Solution();
    }
};