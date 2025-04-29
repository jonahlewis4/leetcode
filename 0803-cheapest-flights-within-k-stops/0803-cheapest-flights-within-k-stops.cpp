class Solution {
    int n;
    vector<vector<int>> flights;
    int src;
    int dst;
    int k;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        this->n = n;
        this->flights = flights;
        this->src = src;
        this->dst = dst;
        this->k = k;
        //return djikstras();
        //return bellmanFord();
        return bfs();

    }
    struct dNode{
        int dest;
        int weight;
        int stops;
    };
    struct edge {
        int dest;
        int weight;
    };
    int djikstras(){
        //djikstras : 
        //find the closest vertex that isn't connected and relax it. 
        //either use a pq or loop through every vertex. Exit when we reach the source. If visited skip 

        priority_queue<dNode, vector<dNode>, decltype([](auto const & a, auto const & b){
            return a.weight > b.weight;
        }) > pq;

        vector<vector<edge>> adjList(n);

        for(auto const & flight : flights){
            int src = flight[0];
            int dest = flight[1];
            int weight = flight[2];
            adjList[src].push_back({
                .dest = dest,
                .weight = weight,
            });
        }
        
        pq.push({
            .dest = src,
            .weight = 0,
            .stops = 0,
        });
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        while(!pq.empty()){
            dNode node = pq.top();
            pq.pop();

            if(node.dest == dst){
                return node.weight;
            }

            if(node.stops >= k + 1){
                continue;
            }

            if(node.weight > dist[node.dest][node.stops]){
                continue;
            }

            dist[node.dest][node.stops] = node.weight;

            for(auto const & neigh : adjList[node.dest]){
                
                
                if(neigh.weight + node.weight >= dist[neigh.dest][node.stops + 1]){
                    continue;
                }
                dist[neigh.dest][node.stops + 1] = neigh.weight + node.weight;
                pq.push({
                    .dest = neigh.dest,
                    .weight = neigh.weight + node.weight,
                    .stops = node.stops + 1,
                });
            }

        }

        return -1;
    }
    int bellmanFord(){
        //bellman ford:
        //relax every vertex. 
        vector<vector<edge>> adjList(n);

        for(auto const & flight : flights){
            int src = flight[0];
            int dest = flight[1];
            int weight = flight[2];
            adjList[src].push_back({
                .dest = dest,
                .weight = weight,
            });
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        int stops = 0;
        while(true){
            if(stops >= k + 1){
                break;
            }
            
            vector<int> newDist = dist;
            for(int i = 0; i < adjList.size(); i++){
                auto const & list = adjList[i];
                for(auto const & edge : list){
                    if(dist[i] == INT_MAX){
                        continue;
                    }
                    if(dist[i] + edge.weight < newDist[edge.dest]){
                        newDist[edge.dest] = dist[i] + edge.weight;
                    }
                }
            }
            dist = newDist;
            stops++;
        }


        return dist[dst] == INT_MAX ? -1 : dist[dst];

    }
    int bfs(){
        //adjacencly list and visited array.

        //also a distance array of the smallest we've found. 

        //bfs k + 1 times.

        vector<vector<edge>> adjList(n);
        for(auto const & flight : flights){
            int src = flight[0];
            int dest = flight[1];
            int weight = flight[2];
            adjList[src].push_back({
                .dest = dest,
                .weight = weight,
            });
        }

        vector<int> dist(n, INT_MAX);
        
        queue<edge> q;
        q.push({
            .dest = src,
            .weight = 0,
        });

        for(int i = 0; i <= k + 1 && !q.empty(); i++){
            int n = q.size();
            for(int TwT = 0; TwT < n; TwT++){
                edge e = q.front();
                q.pop();

                if(e.weight > dist[e.dest]){
                    continue;
                }

                dist[e.dest] = e.weight;

                for(auto const & neigh : adjList[e.dest]){
                    int newWeight = neigh.weight + e.weight;
                    if(newWeight < dist[neigh.dest]){
                        q.push({
                            .dest = neigh.dest,
                            .weight = newWeight,
                        });
                    }
                }
            }
        }
         
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }

};