class Solution {
private:
    struct car{
        int start;
        double time;
    };
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<car> cars(position.size());
        for(int i = 0; i < position.size(); i++){
            cars[i] = {position[i], ((double)target - position[i]) / speed[i]};
        }

        std::sort(cars.begin(), cars.end(), [](car &c1, car &c2){
            return c1.start < c2.start;
        });


        std::stack<car> stack;
        for(const auto & car : cars){
            while(!stack.empty() && stack.top().time <= car.time){
                stack.pop();
            }
            stack.push(car);
        }
        
        return stack.size();
    }
};