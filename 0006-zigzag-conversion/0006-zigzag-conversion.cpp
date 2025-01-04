class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        int colSize = ceil((double)s.size() / (2 * numRows - 2)) * (numRows - 1);
        cout<<"Colsize: "<<colSize<<endl;
        cout<<"s size: "<<s.size()<<endl;
        vector<vector<char>> grid(numRows, vector<char>(colSize, ' '));

        int r = 0;
        int c = 0;
        int i   = 0;
        while(i < s.size())
        {
            while(i < s.size() && r < numRows && c < colSize){ 
                cout<<"i: "<<i<<endl;
                cout<<"r: "<<r<<endl;
                cout<<"c: "<<c<<endl;
                cout<<endl;
                grid[r][c] = s[i];
                r++;
                i++;
            }
            r -= 2;
            c++;
            while(i < s.size() && r > 0 && c < colSize){
                cout<<"i: "<<i<<endl;
                cout<<"r: "<<r<<endl;
                cout<<"c: "<<c<<endl;
                cout<<endl;
                grid[r][c] = s[i];
                r--;
                c++;
                i++;
            }
        }
        cout<<"built grid"<<endl;
        string res = "";
        for(int    r = 0; r < numRows; r++){
            for(int c = 0; c < grid[r].size(); c++){
                if(grid[r][c] != ' '){
                    res += grid[r][c];
                }
            }
        }
        return res;
    }
};