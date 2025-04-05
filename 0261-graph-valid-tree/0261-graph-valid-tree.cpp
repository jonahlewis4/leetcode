class Solution {
private:
    struct Dsu{
        struct node{
            int parentId;
            int size;
        };
        vector<node> nodes;
        Dsu(int n){
            nodes.resize(n, {0, 1});
            for(int i = 0; i < n; i++){
                nodes[i].parentId = i;
            }
        }

        int find(int i){
            if(nodes[i].parentId == i){
                return i;
            }
            nodes[i].parentId = find(nodes[i].parentId);
            return nodes[i].parentId;
        }

        bool Union(int a, int b){
            int rootA = find(a);
            int rootB = find(b);

            if(rootA == rootB){
                return true;
            }

            node & nodeA = nodes[rootA];
            node & nodeB = nodes[rootB];

            if(nodeA.size < nodeB.size){
                nodeB.size += nodeA.size;
                nodeA.parentId = nodeB.parentId;
            } else {
                nodeA.size += nodeB.size;
                nodeB.parentId = nodeA.parentId;
            }

            return false;
        }
    };
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //check that number of edges = n - 1
        if(edges.size() != n - 1){
            return false;
        }

        Dsu dsu(n);
        for(const auto & edge : edges){
            if(dsu.Union(edge[0], edge[1])){
                return false;
            }
        }

        return true;
    }
};