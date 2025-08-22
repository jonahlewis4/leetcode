class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        struct car {
            int position;
            double remainingTime;
        };
        vector<car> cars(position.size());
        for(int i = 0; i < position.size(); i++) {
            cars[i] = {
                .position = position[i],
                .remainingTime = (double) (target - position[i]) / speed[i]
            };
        }

        sort(cars.begin(), cars.end(), [](car a, car b){
            return a.position < b.position;
        });

        stack<double> stk;
        for(int i = 0; i < cars.size(); i++) {
            while(!stk.empty() && stk.top() <= cars[i].remainingTime){
                stk.pop();
            }
            stk.push(cars[i].remainingTime);
        }
        return stk.size();
    }
};