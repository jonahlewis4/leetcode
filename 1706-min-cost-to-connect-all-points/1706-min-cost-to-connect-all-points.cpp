class Solution {
private:
    class DSU {
        vector<int> root;
        vector<int> size;
    public:
        DSU(int n){
            root.resize(n);
            for(int i = 0; i < n; i++){
                root[i] = i;
            }
            size.resize(n, 1);
        }

        int find(int i) {
            if(root[i] == i){
                return i;
            }
            root[i] = find(root[i]);
            return root[i];
        }

        bool Union(int a, int b){
            int aRoot = find(a);
            int bRoot = find(b);
            if(aRoot == bRoot){
                return false;
            }

            if(size[aRoot] < size[bRoot]){
                size[bRoot] += size[aRoot];
                root[aRoot] = bRoot;
            } else {
                size[aRoot] += size[bRoot];
                root[bRoot] = aRoot;
            }

            return true;
        }
    };
private:
    struct point {
        int x;
        int y;
        int dist(point p2){
            return abs(p2.x - x) + abs(p2.y - y);
        }
    };
    struct distance {
        int point1;
        int point2;
        int distance;
    };
public:
    int minCostConnectPoints(vector<vector<int>>& _points) {
        //MInimum spanning tree -
        //kruskal's
        vector<point> points;
        vector<distance> distances;
        for(const auto & point : _points) {
            int x = point[0];
            int y = point[1];
            points.push_back({
                .x = x,
                .y = y
            });
        }
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1 ; j < points.size(); j++){
                distances.push_back({
                    .point1 = i,
                    .point2 = j,
                    .distance = points[i].dist(points[j])
                });
            }
        }

        sort(distances.begin(), distances.end(), [](const auto & a, const auto & b){
            return a.distance < b.distance;
        });

        DSU dsu(points.size());

        int total = 0;
        for(const auto & distance : distances){
            if(dsu.Union(distance.point1, distance.point2)){
                total += distance.distance;
            }
        }

        return total;
        
    }
};