class Solution {
public:
    int countCollisions(string directions) {
        stack<char> cars;
        int collisions = 0;
        for(const char dir : directions) {
            switch (dir) {
                case 'S': {
                    while(!cars.empty() && cars.top() == 'R'){
                        collisions++;
                        cars.pop();
                    }
                    while(!cars.empty()){cars.pop();}
                    cars.push('S');
                    break;
                }
                case 'L': {
                    if(cars.empty()){
                        break;
                    }

                    if(cars.top() == 'R'){
                        collisions += 2;
                        cars.pop();
                        while(!cars.empty() && cars.top() == 'R'){
                            collisions++;
                            cars.pop();
                        }
                        while(!cars.empty()){cars.pop();}
                        cars.push('S');
                        break;
                    }

                    if(cars.top() == 'S'){
                        collisions++;
                        break;
                    }
                    break;
                }
                default: {
                    if(cars.empty()) {
                        cars.push(dir);
                        break;
                    }

                    if(cars.top() != 'R'){
                        cars.pop();
                    } 
                    cars.push('R');
                    break;
                }
            }
        }

        return collisions;
    }
};