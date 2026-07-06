class Solution {
    string hash(int x, int y) {
        return to_string(x) + "|" + to_string(y);
    }
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x + y < target) {
            return false;
        }

        stack<pair<int, int>> stack;
        unordered_set<string> set;
        stack.push({0, 0});
        set.insert(hash(0, 0));
        while(!stack.empty()) {
            pair<int, int> p = stack.top();
            //cout<<p.first<<" "<<p.second<<endl;
            stack.pop();
            if(p.first + p.second == target) {
                return true;
            }

            const auto& update = [&stack, &set, this](int x, int y) {
                string hashed = hash(x,y);
                if(set.contains(hashed)) {
                    return;
                }
                stack.push({x,y});
                set.insert(hashed);
            };

            update(x, p.second);
            update(p.first, y);
            update(0, p.second);
            update(p.first, 0);
            
            int gained = max(0, min(p.first, y - p.second));
            update(p.first - gained, p.second + gained);

            int gained2 = max(0, min(p.second, x - p.first));
            update(p.first + gained2, p.second - gained2);
        }
        return false;
    }
};