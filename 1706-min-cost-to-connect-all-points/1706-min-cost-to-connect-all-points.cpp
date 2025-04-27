class Solution {
    struct point{
        int x;
        int y;
        int manhat(const point & p2) const{
            return abs(p2.x - x) + abs(p2.y - y);
        }
    };
    struct edge{
        int i;
        int weight;
    };
public:
    int minCostConnectPoints(vector<vector<int>>& _points) {
        //prim's algorithm (vertices edition)

        //the graph is dense so we do the V^2 variation instead of the (E + V) log V

        int n = _points.size();
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        vector<point> points;
        for(auto const & p : _points){
            points.push_back({
                .x = p[0],
                .y = p[1],
            });
        }

        //prims with pq : find closest one that isn't already connected.

        int connectedCount = 1;
        vector<bool> connected(n, false);
        priority_queue<edge, vector<edge>, decltype([](const auto & a, const auto & b){
            return a.weight > b.weight;
        }) > pq;

        vector<vector<edge>> adjList(n);
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                adjList[i].push_back({
                    .i = j,
                    .weight = points[i].manhat(points[j]),
                });
                adjList[j].push_back({
                    .i = i,
                    .weight = points[j].manhat(points[i]),
                });
            }
        }

        pq.push({
            .i = 0,
            .weight = 0,
        });

        while(!pq.empty() && connectedCount < n){
            edge e = pq.top();
            pq.pop();

            if(connected[e.i]){
                continue;
            }

            connected[e.i] = true;
            connectedCount++;
            //dist[e.i] = min(dist[e.i], e.weight);

            for(auto const & n : adjList[e.i]) {
                if(connected[n.i]){
                    continue;
                }
                if(n.weight < dist[n.i]){
                    dist[n.i] = n.weight;
                    pq.push(n);
                }
            }
        }

        int sum = 0;
        for(auto const & i : dist){
            sum += i;
        }
        return sum;
    }
};