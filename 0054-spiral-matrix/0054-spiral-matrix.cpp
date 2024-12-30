class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;
        int left = 0;

        int moves = matrix.size() * matrix[0].size();

        vector<int> result;
        while(moves > 0){
            for(int c = left; c <= right; c++){
                //cout<<matrix[top][c]<<endl;
                result.push_back(matrix[top][c]);
                moves--;
                if(moves == 0){
                    return result;
                }
            }
            top++;
            for(int r = top; r <= bottom; r++){
                //cout<<matrix[r][right]<<endl;
                result.push_back(matrix[r][right]);
                moves--;
                if(moves == 0){
                    return result;
                }
            }
            right--;
            for(int c = right; c >= left; c--){
                //cout<<matrix[bottom][c]<<endl;
                result.push_back(matrix[bottom][c]);
                moves--;
                if(moves == 0){
                    return result;
                }
            }
            bottom--;
            for(int r = bottom; r >= top; r--){
                //cout<<matrix[r][left]<<endl;
                result.push_back(matrix[r][left]);
                moves--;
                if(moves == 0){
                    return result;
                }
            }
            left++;
        }
        return result;
    }
};