class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        colswap(matrix);

    }
    void transpose(vector<vector<int>> & matrix){
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j <= i; j++){
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void colswap(vector<vector<int>> & matrix){
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size() / 2; j++){
                std::swap(matrix[i][j], matrix[i][matrix[i].size() - j - 1]);
            }
        }
    }

    void printMatrix(vector<vector<int>> & matrix){
        for(const auto & row : matrix){
            for (const auto & col : row){
                cout<<col<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};