class Solution {
    class DSU {
        vector<int> roots;
        vector<int> sizes;

    public:
        DSU(int n){
            roots.resize(n);
            sizes.resize(n, 1);
            iota(roots.begin(), roots.end(), 0);
        }

        int Find(int i) {
            if(roots[i] == i) {
                return i;
            }

            roots[i] = Find(roots[i]);
            return roots[i];
        }

        void Union(int a, int b) {

            int aRoot = Find(a);
            int bRoot = Find(b);

            if(aRoot == bRoot) {
                return;
            }

            //merge smaller of a and b into larger
            if(sizes[aRoot] > sizes[bRoot]) {
                swap(aRoot, bRoot);
            }

            //aRoot is the smaller of the two, merge a into b

            sizes[bRoot] += sizes[aRoot];
            roots[aRoot] = bRoot;
        }

        unordered_map<int, char> smallestInEachUnion() {
            //find on each to path compress
            unordered_map<int, char> smallest;
            for(int i = 0; i < roots.size(); i++){
                int root = Find(i);
                if(smallest.find(root) == smallest.end()){
                    smallest[root] = i + 'a';
                }

            }
            return smallest;
        }

    };
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        //union find. Find smallest in each root.

        //set s[i] to smallest(find(s[i]));

        DSU dsu(26);
        for(int i = 0; i < s1.size(); i++){
            dsu.Union(s1[i] - 'a', s2[i] - 'a');
        }

        unordered_map<int, char> smallest = dsu.smallestInEachUnion();


        for(int i = 0; i < baseStr.size(); i++){
            baseStr[i] = smallest[dsu.Find(baseStr[i] - 'a')];
        }
        

        return baseStr;
    }
};