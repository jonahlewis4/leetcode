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
        FenwickTree tree(max_element(people.begin(), people.end())->front() + 1);
        vector<vector<int>> res;
        for(int i = 0; i < people.size(); i++) {
            int bestI = -1;
            for(int j = 0; j < people.size(); j++) {
                int height = people[j].front();
                if(height == -1) {
                    continue;
                }
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
            people[bestI].front() = -1;
        }

        return res;
    }
};