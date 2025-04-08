class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);

        
        for(int i = 0; i < rowIndex; i++){
            int before = 1;
            for(int j = i; j > 0; j--){
                row[j] = row[j] + row[j - 1];
            }  
        }
        return row;
    }
};