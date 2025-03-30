class Solution {
    class DJU{
        struct item {
            int root;
            int size = 1;

            item(int _root){
                root = _root;
            }
        };

        vector<item> items;

    public:
        DJU(int n){
            items.resize(n, item(-1));
            for(int i = 0; i < n; i++){
                items[i].root = i;
            }
        }

        item& Find(int i) {
            if(items[i].root == i){
                return items[i];
            }
            items[i].root = Find(items[i].root).root;
            return items[items[i].root];
        }

        bool Union(int i1, int i2) {
            item &root1 = Find(i1);
            item &root2 = Find(i2);

            if(root1.root == root2.root){
                return true;
            }

            if(root1.size > root2.size){
                root2.size += root1.size;
                root1.root = root2.root;
            } else {
                root1.size += root2.size;
                root2.root = root1.root;
            }

            return false;
        }

    };

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = 0;
        unordered_set<int> present;
        for(const auto & edge : edges){
            present.insert(edge[0]);
            present.insert(edge[1]);
        }

        DJU dju(present.size() + 1);
        for(const auto & edge : edges){
            if(dju.Union(edge[0], edge[1])){
                return edge;
            }
        }

        return {};
    }
};