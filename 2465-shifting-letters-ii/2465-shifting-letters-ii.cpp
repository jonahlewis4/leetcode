class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> sums(s.size() + 1);
        for(const auto & shift : shifts){
            if(shift[2] == 0){
                sums[shift[0]] -= 1;
                sums[shift[1] + 1] += 1;
            } else {
                sums[shift[0]] += shift[2];
                sums[shift[1] + 1] -= shift[2];
            }
            
        }
        for(int i = 1; i < sums.size(); i++){
            sums[i] += sums[i - 1];
        }
        for(int i = 0; i < sums.size(); i++){
            if(sums[i] > 0){
                s[i] = (s[i] - 'a' + sums[i]) % 26 + 'a';
            } else {
                s[i] = (s[i] - 'z' + sums[i]) % 26 + 'z';
            }
    
            
        }


        return s;
    }
};