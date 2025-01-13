class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i = 1; i <= n; i++){
            string local;
            bool fizzyBuzzy = false;
            if(i % 3 == 0){
                local += "Fizz";
                fizzyBuzzy = true;
            } 
            if(i % 5 == 0){
                local += "Buzz";
                fizzyBuzzy = true;
            }
            if(!fizzyBuzzy){
                res.push_back(to_string(i));
            } else {
                res.push_back(local);
            }
        }
        return res;
    }
};