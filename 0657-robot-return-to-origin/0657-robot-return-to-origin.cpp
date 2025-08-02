class Solution {
public:
    bool judgeCircle(string moves) {
        int xOffset = 0;
        int yOffset = 0;
        for(const auto & move : moves) {
            switch (move) {
                case 'R':
                    xOffset++;
                    break;
                case 'L':
                    xOffset--;
                    break;
                case 'U':
                    yOffset++;
                    break;
                case 'D':
                    yOffset--;
                    break;
            }
        }
        return !xOffset and !yOffset;

    }
};