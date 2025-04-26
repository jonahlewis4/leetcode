class Solution {
    struct item{
        int r;
        int c;
        int weight;
    };

    class compareWeight{
    public:
        bool operator() (const auto & a, const auto & b) {
            return a.weight < b.weight;
        }
    };
    
    vector<tuple<int, int>> dirs = {
        {0,1},
        {1,0},
        {-1, 0},
        {0, -1},
    };

    class DSU {
        vector<int> size;
        vector<int> root;
    public:
        DSU(int n){
            size.resize(n, 1);
            root.resize(n, -1);
            iota(root.begin(), root.end(), 0);
        }

        int Find(int i){
            if(root[i] == i){
                return i;
            }
            root[i] = Find(root[i]);
            return root[i];
        }
        void Union(int a, int b){
            int aRoot = Find(a);
            int bRoot = Find(b);

            if(aRoot == bRoot){
                return;
            }

            if(size[aRoot] < size[bRoot]){
                swap(aRoot, bRoot);
            }

            //aRoot is the larger one so move b into a.

            root[bRoot] = aRoot;
            size[aRoot] += size[bRoot];
        }
    };
    

    int n;
public:
    int swimInWater(vector<vector<int>>& grid) {
        //DSU, sort by weight.

        //union the smaller adjecent squares with the current square. 
        //if first in same as last return current weight;

        n = grid.size();
        vector<item> points(n * n);

        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                points[grid[r][c]] = {
                    .r = r,
                    .c = c,
                    .weight = grid[r][c],
                };
            }
        }

        //we can use counting sort??!?? (if I get it to work we gonna run this back with it)

        DSU dsu(n * n);
        for(auto const & point : points){
            //merge point with all of its neighboors which are smaller. 
            for(auto const & dir : dirs){
                auto const [rOff, cOff] = dir;
                int newR = point.r + rOff;
                int newC = point.c + cOff;

                if(newR < 0 || newC < 0 || newR >= n || newC >= n){
                    continue;
                }
                if(grid[newR][newC] > grid[point.r][point.c]){
                    continue;
                }
                dsu.Union(flatten(newR, newC), flatten(point.r, point.c));
            }
            if(dsu.Find(flatten(0, 0)) == dsu.Find(flatten(n - 1, n - 1))){
                return point.weight;
            }
        }
        return n * n;

    }

    int flatten(int r, int c) const {
        return r * n + c;
    }
};