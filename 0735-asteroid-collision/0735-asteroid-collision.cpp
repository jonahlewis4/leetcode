class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       vector<int> stack;
       for(int asteroid : asteroids){
            bool oneRemains = true;
            while(!stack.empty() && (stack.back() > 0) && (asteroid < 0)){
                int top = stack.back();
                stack.pop_back();

                if(abs(top) > abs(asteroid)){
                    asteroid = top;
                } else if (abs(top) == abs(asteroid)){
                    oneRemains = false;
                    break;
                }
            }
            if(oneRemains){
                stack.push_back(asteroid);
            }
        } 
        return stack;
    }
};