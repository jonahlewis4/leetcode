class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> row(rowIndex, 1);

        
        for(int i = 0; i < rowIndex; i++){
            int before = 1;
            for(int j = 1; j < i; j++){
                int old = row[j];
                row[j] = row[j] + before;
                before = old;
            }  
        }
        return row;
    }
};