class Solution {
    template <typename F>
    void funcOrDefault(unordered_map<int, int>& map, int key, int update, F f) {
        if(!map.contains(key)) {
            map[key] = update;
        } else {
            map[key] = f(map[key], update);
        }
    }
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, int> xFirst;
        unordered_map<int, int> xLast;
        unordered_map<int, int> yFirst;
        unordered_map<int, int> yLast;

        for(const vector<int>& building : buildings) {
            int x = building[0];
            int y = building[1];

            const auto & min = [](int a, int b) {return std::min(a, b);};
            const auto & max = [](int a, int b) {return std::max(a, b);};


            funcOrDefault(xFirst, x, y, min);
            funcOrDefault(xLast, x, y, max);
            funcOrDefault(yFirst, y, x, min);
            funcOrDefault(yLast, y, x, max);
        }

        int covered = 0;

        for(const vector<int>& building : buildings) {
            int x = building[0];
            int y = building[1];

            if(y == xFirst[x]){
                continue;
            }

            if(y == xLast[x]){
                continue;
            }

            if(x == yFirst[y]) {
                continue;
            }

            if(x == yLast[y]) {
                continue;
            }

            covered++;
        }

        return covered;
    }
};