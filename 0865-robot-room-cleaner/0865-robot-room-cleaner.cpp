//things that could be improved upon
//can be improved by using dir vector
//re-orient at end of function by assuuming if we turn around and move we're back
//in the proper direction, removing need to track current face. 

class Solution {
private:    
    class squareHandler{
        Robot& _robot;
        unordered_map<int, unordered_map<int, bool>> path;
        int _face = 0;
        void exhaustIfUnexausted(int x, int y, int returnFace) {
            if(inPath(x, y)) {
                return;
            }
            returnTo((returnFace + 2) % 4);
            if(_robot.move()){
                exhaust(x, y, returnFace);
            }
            
        }
        void returnTo(int returnFace) {
            while(_face != returnFace) {
                _face++;
                _face %= 4;
                _robot.turnRight();
            }
        }
        void addToPath(int x, int y){
            path[x][y] = true;
        }
        void removeFromPath(int x, int y) {
            path[x][y] = false;
        }
        bool inPath(int x, int y) {
            return path[x][y];
        }
    public: 
        squareHandler(Robot& robot) : _robot(robot) {
        }
        void exhaust(int x, int y, int returnFace) {
            addToPath(x, y);
            _robot.clean();
            exhaustIfUnexausted(x + 1, y, 3);
            exhaustIfUnexausted(x - 1, y, 1);
            exhaustIfUnexausted(x, y + 1, 0);
            exhaustIfUnexausted(x, y - 1, 2);

            returnTo(returnFace);
            _robot.move();
        }
    };
public:
    void cleanRoom(Robot& robot) {
        squareHandler(robot).exhaust(0, 0, 0);
    }
};