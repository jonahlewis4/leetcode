class Solution {
    struct point{
        int x;
        int y;
        int dist(const point& p2){
            return abs(x - p2.x) + abs(y - p2.y);
        }
    };

    struct closest{
        int node;
        int weight;
    };

    struct compareClosest {
        bool operator() (const closest & a, const closest & b){
            return a.weight > b.weight; //return true if a has LOWER priority than b
        }
    };
    
public:
    int minCostConnectPoints(vector<vector<int>>& _points) {
        int n = _points.size();
        vector<point> points(n);
        for(int i = 0; i < n; i++){
            points[i] = {
                .x = _points[i][0],
                .y = _points[i][1]
            };
        }

        //all nodes are connected so we will calculate the distance while finding neighboors. This saves us from doing a few calculations.          
        
        //prim's algorithm.

        //take top of prioirty queue (the closest node)
        //if already visited, continue
        
        //makr as visited

        //push all unvisited neighboors to the priority queue.

        vector<bool> visited(n, false);
        int visitCount = 0;

        priority_queue<closest, vector<closest>, compareClosest> pq;
        
        // for(int i = 1; i < points.size(); i++){
        //     pq.push({
        //         .node = i,
        //         .weight = points[0].dist(points[i])
        //     });
        // }
        pq.push({
            .node = 0,
            .weight = 0
        });

        int cost = 0;
        while(!pq.empty() && visitCount < n){
            auto closest = pq.top();
            pq.pop();

            if(visited[closest.node]){
                continue;
            }
            visited[closest.node] = true;
            visitCount++;

            cost += closest.weight;

            //push all unvisited neighboors
            point &pt = points[closest.node];
            for(int i = 0; i < n; i++){
                if(i == closest.node){
                    continue;
                }
                if(visited[i]){
                    continue;
                }
                pq.push({
                    .node = i,
                    .weight = pt.dist(points[i])
                });
            }

        }
        return cost;

    }

};