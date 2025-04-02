class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size() == 0){
            return 0;
        }

        int open = 0;
        int close = 0;

        int unmatched = 0;
        for(char c : s){
            if(c == '('){
                open++;
            }
            if(c == ')'){
                if(open <= 0){
                    unmatched++;
                } else {
                    open--;
                }
                
            }
        }
        
        return unmatched + open;
    }
};