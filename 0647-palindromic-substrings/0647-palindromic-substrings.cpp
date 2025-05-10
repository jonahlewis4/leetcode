class Solution {
public:
    int countSubstrings(string s) {
        //count all palindromes originating with 1 center 
        //add with all palindromes originating with 2 center.

        int total = 1;

        for(int i = 0; i + 1 < s.size(); i++){
            total += originatingFrom(i, i, s);
            total += originatingFrom(i, i + 1, s);
        }
        return total;
    }   

    int originatingFrom(int l, int r, const string &s) const {
        int created = 0;
        while(l >= 0 && r < s.size()){
            if(s[l] != s[r]){
                return created;
            }
            created++;
            l--;
            r++;
        }
        return created;
    }
};