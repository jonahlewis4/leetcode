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
        vector<point> points;
        for(auto const & p : _points){
            points.push_back({
                .x = p[0],
                .y = p[1],
            });
        }

        //prims with pq : find closest one that isn't already connected.

        int connectedCount = 0;
         //prims with pq : find closest one that isn't already connected.
        
        //without pq : use the closest one as the node in the next iteration because that's
        //the new info we need to add. The goal is to still find the closest one that isn't
        //already connected.
        vector<bool> connected(n, false);

        int sum = 0;
        int newestNode = 0;
        while(connectedCount < n - 1){
            connected[newestNode] = true;
            connectedCount++;
            int closestNode = -1;
            for(int i = 0; i < n; i++){
                if(connected[i]){
                    continue;
                }
                int newDistance = points[newestNode].manhat(points[i]);
                dist[i] = min(dist[i], newDistance);
                if(closestNode == -1 || dist[closestNode] > dist[i]){
                    closestNode = i;
                }
            }
            sum += dist[closestNode];
            newestNode = closestNode;
            
        }
        
        return sum;
    }
};