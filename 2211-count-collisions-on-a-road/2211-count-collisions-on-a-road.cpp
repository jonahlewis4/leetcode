class Solution {
public:
    int countCollisions(string directions) {
        int collisions = 0;
        int last = 0;
        constexpr int S = -1;
        for(const char dir : directions) {
            switch (dir) {
                case 'S': {
                    if(last > 0) {
                        collisions += last;
                        last = 0;
                    }
                    last = S;
                    break;
                }
                case 'L': {
                    if(last == 0){
                        break;
                    }

                    if(last > 0){
                        collisions += last + 1;
                    
                        last = S;
                        break;
                    }

                    if(last == S){
                        collisions++;
                        break;
                    }
                    break;
                }
                default: {
                    if(last == 0) {
                        last++;
                        break;
                    }

                    if(last < 0){
                        last = 0;
                    } 
                    last++;
                    break;
                }
            }
        }

        return collisions;
    }
};