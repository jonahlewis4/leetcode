/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
private:    
    class squareHandler{
        Robot& _robot;
        unordered_map<int, unordered_map<int, bool>> path;
        int _face = 0;
        unordered_map<int, unordered_map<int, bool>> squares;
        void exhaustIfUnexausted(int x, int y, int returnFace) {
            if(inPath(x, y)) {
                return;
            }
            if(!exhausted(x, y)) {
                returnTo((returnFace + 2) % 4);
                if(_robot.move()){
                    exhaust(x, y, returnFace);
                } else {
                    setExhausted(x, y);
                }
            }
        }
        bool exhausted(int x, int y) {
            return squares[x][y];
        }
        void setExhausted(int x, int y) {
            squares[x][y] = true;;
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

            setExhausted(x, y);
            returnTo(returnFace);
            _robot.move();
            removeFromPath(x, y);
        }
    };
public:
    void cleanRoom(Robot& robot) {
        squareHandler(robot).exhaust(0, 0, 0);
    }
};