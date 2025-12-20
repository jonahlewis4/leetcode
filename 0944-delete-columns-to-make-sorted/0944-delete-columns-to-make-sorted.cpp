class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int deleted = 0;
        for(int col = 0; col < strs.front().size(); col++){
            for(int row = 1; row < strs.size(); row++){
                char prevC = strs[row - 1][col];
                char curC = strs[row][col];

                if(curC < prevC) {
                    deleted++;
                    break;
                }
            }
        }

        return deleted;
    }
};