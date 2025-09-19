class Spreadsheet {
    vector<vector<int>> grid;
    static int colCount;
private:
    tuple<int, int> parseCellString(const string& s){
        char colChar = s.front();
        int colNum = colChar - 'A';

        string rowStr = s.substr(1);
        int rowNum = stoi(rowStr) - 1;

        return {rowNum, colNum};
    }

    int parseCellOrRawString(const string& s) {
        if(isalpha(s.front())){
            const auto & [r, c] = parseCellString(s);
            return grid[r][c];
        }

        return stoi(s);
    }
public:
    Spreadsheet(int rows) {
        grid.resize(rows, vector<int>(colCount, 0));
    }
    
    void setCell(const string& cell, int value) {
        const auto & [r, c] = parseCellString(cell);
        grid[r][c] = value;
    }
    
    void resetCell(const string&  cell) {
        const auto & [r, c] = parseCellString(cell);
        grid[r][c] = 0;
    }
    
    int getValue(const string& formula) {
        int plusIdx = formula.find('+');
        string val1Str = formula.substr(1, plusIdx - 1);
        int q1Val = parseCellOrRawString(val1Str);

        string val2Str = formula.substr(plusIdx + 1);
        int q2Val = parseCellOrRawString(val2Str);

        return q1Val + q2Val;
    }

};
int Spreadsheet::colCount = 'Z' - 'A' + 1;

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */