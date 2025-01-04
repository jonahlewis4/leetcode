class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        
        vector<vector<char>> grid(numRows, vector<char>(s.size(), ' '));

        int r = 0;
        int c = 0;
        int i   = 0;
        while(i < s.size())
        {
            while(i < s.size() && r < numRows){ 
                grid[r][c] = s[i];
                r++;
                i++;
            }
            r -= 2;
            c++;
            while(i < s.size() && r > 0 && c < grid[r].size()){
                grid[r][c] = s[i];
                r--;
                c++;
                i++;
            }
        }

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