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
        FenwickTree tree(people.size());
        vector<vector<int>> res(people.size());
        int n = people.size();
        sort(people.begin(), people.end(), [](
            vector<int>& v1, vector<int>& v2){
                if(v1.front() < v2.front()) {
                    return true;
                }
                if(v1.front() > v2.front()) {
                    return false;
                }
                return v1.back() > v2.back();
            }
        );
        int endI = people.size() - 1;

        for(int i = 1; i < people.size(); i++) {
            tree.update(i, 1);
        }

        for(int i = 0; i < n; i++) {
            int height = people[i].front();
            int place = people[i].back();

            //place this in the # place empty spot from the front
            int l = 0;
            int r = n - 1;
            while(l <= r) {
                int m= l + (r - l)/2;
                int spot = tree[m];
                if(spot <= place) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            
            res[r] = people[i];
            tree.update(r+1, -1);
        }

        return res;
    }
};