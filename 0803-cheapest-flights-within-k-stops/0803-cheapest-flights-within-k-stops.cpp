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

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        Args args;
        args.n = n;
        args.flights = flights;
        args.src = src;
        args.dst = dst;
        args.k = k;
        return BellmanFord(args).Solution();
    }
};