class Solution {
    class UnionFind{
    private:
        struct Group{
            int root;
            int size;
        };
        int numGroups;
        vector<Group> u;

        Group find(int i){
            //get root
            int root = i;
            while(u[root].root != root){
                root = u[root].root;
            }


            //path compression
            while(i != root){
                int next = u[i].root;
                u[i].root = root;
                i = next;
            }

            return u[root];
        }


    public:
        UnionFind(int n){
            u = vector<Group>(n);
            for(int i = 0; i < n; i++){
                u[i] = {
                    .root = i,
                    .size = 1
                };
            }
            numGroups = n;
        }

        void combine(int x, int y){
            Group xG = find(x);
            Group yG = find(y);

            if(yG.root == xG.root) {
                return;
            }


            if(xG.size > yG.size){
                u[yG.root] = {
                    .root = xG.root,
                    .size = xG.size + yG.size
                };
                u[xG.root].size = xG.size + yG.size;
            } else{
                u[xG.root] = {
                    .root = yG.root,
                    .size = xG.size + yG.size
                };
                u[yG.root].size = xG.size + yG.size;
            }
            numGroups--;
        }
        int size(){
            return numGroups;
        }
    };
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        UnionFind u = UnionFind(n);

        std::sort(logs.begin(), logs.end(), [](const auto & a, const auto & b){
            return a[0] < b[0];
        });


        for(const auto & log : logs){
            int person1 = log[1];
            int person2 = log[2];
            u.combine(log[1], log[2]);
            if(u.size() == 1){
                return log[0];
            }
        }
        return -1;

    }

    
};