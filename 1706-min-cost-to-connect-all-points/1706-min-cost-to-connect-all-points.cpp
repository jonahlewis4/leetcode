class Solution {
    struct point{
        int x;
        int y;
        int distanceFrom(const point &p2){
            return abs(x - p2.x) + abs(y - p2.y);
        }
    };
public:
    int minCostConnectPoints(vector<vector<int>>& _points) {
        //kurskal's or prim's.
    
        //use prim's based on vertices because there are many edges.
        //this means the graph is dense.
        //prim's based on vertices is best for dense graphs.


        //convert points to list of points.
        vector<point> points(_points.size());
        for(int i = 0; i < _points.size(); i++){
            int x = _points[i][0];
            int y = _points[i][1];
            points[i] = {
                .x = x,
                .y = y
            };
        }
        //start with a vertex.
        //use the verison without a priority queue because it is a dense graph.
        int vertexI = 0;
        vector<int> dist(points.size(), INT_MAX);
        dist[vertexI] = 0;
        vector<bool> visited(points.size(), false);
        int visitCount = 1;
        int res = 0;
        while(visitCount < visited.size()){
            visited[vertexI] = true;
            visitCount++;
            int nextVertexI = -1;
            for(int i = 0; i < points.size(); i++){
                if(visited[i]){
                    continue;
                }
                int newDistance = points[i].distanceFrom(points[vertexI]);
                dist[i] = min(dist[i], newDistance);
                if(nextVertexI == -1 || dist[i] < dist[nextVertexI]){
                    nextVertexI = i;
                }
            }
            vertexI = nextVertexI;
            res += dist[vertexI];
        }

        return res;
        
    }
};