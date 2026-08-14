class Solution {
    class FenwickTree {
        vector<int> tree;

    public:
        FenwickTree(int size) {
            tree.resize(size + 1);
        }

        int sum(int i) const{
            i++;
            int res = 0;
            for(; i > 0; i -= (i & -i)){
                res += tree[i];
            }
            return res;
        }

        int operator[](int i) const {
            return sum(i);
        }

        void update(int i, int delta) {
            i++;
            for(; i < tree.size(); i += (i & -i)) {
                tree[i] += delta;
            }
        }
        
    };
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int highest = INT_MIN;
        for(const vector<int>& v : people) {
            highest = max(v.front(), highest);
        }
        FenwickTree tree(highest + 1);
        vector<vector<int>> res;
        int n = people.size();
        for(int i = 0; i < n; i++) {
            int bestI = -1;
            for(int j = 0; j < people.size(); j++) {
                int height = people[j].front();
                int targetGte = people[j].back();
                if(res.size() - tree[height - 1] == targetGte) {
                    if(bestI == -1 || people[bestI].front() > height){
                        bestI = j;
                    }
                }
            }
            res.push_back(people[bestI]);

            int bestHeight = people[bestI].front();
            
            tree.update(bestHeight, 1);
            people.erase(people.begin() + bestI);
        }

        return res;
    }
};