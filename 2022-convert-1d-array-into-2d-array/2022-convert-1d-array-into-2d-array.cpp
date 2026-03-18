class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res(m, vector<int>(n));
        
        if(m * n != original.size()) {
            return {};
        }

        for(int i = 0; i < original.size(); i++) {
            int r = i / n;
            int c = i - (n * r);

            cout<<r<<endl;
            cout<<c<<endl;
            cout<<endl;
            res[r][c] = original[i];
        }

        return res;
    }
};