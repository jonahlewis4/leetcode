class Solution {

    class Kruskals {
    private:
        class DSU{
            vector<int> root;
            vector<int> size;
        public:
            DSU(int n){
                size.resize(n, 1);
                root.resize(n, -1);
                iota(root.begin(), root.end(), 0);
            }
            int Find(int i) {
                if(root[i] == i){
                    return i;
                }
                root[i] = Find(root[i]); //path compression
                return root[i];
            }
            void Union(int a, int b) {
                int aRoot = Find(a);
                int bRoot = Find(b);
                if(aRoot == bRoot){
                    return;
                }

                //set aRoot to be the larger of the two and merge bRoot into aRoot
                if(size[aRoot] < size[bRoot]){
                    swap(aRoot, bRoot);
                }

                size[aRoot] += size[bRoot];
                root[bRoot] = aRoot;
            }

            bool Connected(int a, int b) {
                return Find(a) == Find(b);
            }
        };
    struct edge {
        int src;
        int dest;
        int weight;
        bool operator<(const edge &other) const {
            return this->weight < other.weight;
        }
    };
    struct point {
        int x;
        int y;
        int operator-(const point &other) const {
            return abs(other.x - x) + abs(other.y - y);
        }
    };
    const vector<vector<int>>& points;

    public:
        Kruskals(const vector<vector<int>>& points) : points(points) {};
        int compute(){
            DSU dsu(points.size());

            vector<point> _points(points.size());
            for(int i = 0; i < points.size(); i++){
                auto const &point = points[i];
                int x = point[0];
                int y = point[1];
                _points[i] = {
                    .x = x,
                    .y = y,
                };
            }

            vector<edge> edges;
            for(int i = 0; i < _points.size(); i++){
                point const &p1 = _points[i];
                for(int j = i + 1; j < _points.size(); j++){
                    point const&p2 = _points[j];
                    int weight = p1 - p2;
                    edges.push_back({
                        .src = i,
                        .dest = j,
                        .weight = weight,
                    });
                }
            }

            sort(edges.begin(), edges.end());


            int total = 0;
            for(auto const & edge : edges){
                if(dsu.Connected(edge.src, edge.dest)){
                    continue;
                }
                total += edge.weight;
                dsu.Union(edge.src, edge.dest);

            }
            return total;
        }
    };

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        return Kruskals(points).compute();
    }
};