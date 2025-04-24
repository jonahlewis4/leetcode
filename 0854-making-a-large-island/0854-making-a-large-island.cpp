class DSU{
private:
    vector<int> root;
    vector<int> size;
public:
    DSU(){

    }
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

        //aRoot is the larger one, merge bRoot into it.
        root[bRoot] = aRoot;
        size[aRoot] += size[bRoot];
    }

    int Size(int i){
        return size[Find(i)];
    }
};

class Solution {
    vector<tuple<int, int>> dirs = {
        {0,1},
        {0,-1},
        {1, 0},
        {-1, 0}
    };

    
    DSU dsu;
    vector<vector<int>> grid;
    int n;
    int m;
public:
    int largestIsland(vector<vector<int>>& grid) {
        //backtracking to get largest island.
        n = grid.size();
        m = grid[0].size();
        this->grid = grid;
        int largestIslandSize = 0;
        
        unionize();
        bool all1s = true;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[r].size(); c++){
                if(grid[r][c] == 0){
                    all1s = false;
                    int islandSize = determineIslandSize(r, c);
                    largestIslandSize = max(islandSize, largestIslandSize);
                } 
            }
        }
        if(all1s){
            return n * m;
        }
        return largestIslandSize;
    }   

    void unionize() {
        //initialize dsu to size n * m
        
        dsu = DSU(n * m);
        //if above or left is 1 unionize the two.

        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(grid[r][c] == 0){
                    continue;
                }
                int aboveR = r - 1;
                int leftC = c - 1;

                if(aboveR >= 0 && grid[aboveR][c] == 1){
                    dsu.Union(flatten(r, c), flatten(aboveR, c));
                }
                if(leftC >= 0 && grid[r][leftC] == 1){
                    dsu.Union(flatten(r, c), flatten(r, leftC));
                }
            }
        }


    }
    //dsu is a one dimensional object. Flatten transforms row, col indexing to single index
    // (it assumes row major)
    inline int flatten(int r, int c) const{
        return r * m + c;
    }

    int determineIslandSize(int r, int  c){
        
        //unordred map of unions to size.
        unordered_set<int> unions;

        //if left root not in unions add it to unions and its size
        //if above root  not in unions add it to unions  and its size
        //if right root  not in unions add it to unions and its size
        //if below root not in unions add it to unions and its size
        for(const auto & dir : dirs){
            auto const [rOffset, cOffset] = dir;
            int newR = r + rOffset;
            int newC = c + cOffset;
            if(newR < 0 || newC < 0 || newR >= n || newC >= m || grid[newR][newC] == 0){
                continue;
            }
            int i = flatten(newR, newC);
            int root = dsu.Find(i);
            if(unions.find(root) == unions.end()){
                unions.insert(root);
            }
        }

        
        int sum = 0;
        //add up the sum of all the unions
        for(const auto & itr : unions){
            sum += dsu.Size(itr);
        }

        //if current is 1, don't add 1,
        //if current is 0, add 1.
        if(grid[r][c] == 1){
            return sum;
        } else {
            return sum + 1;
        }
        
    }

};