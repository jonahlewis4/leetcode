class Solution {

private:
    bool consec(char a, char b) const {
        if(abs(a - b) == 1){
            return true;
        }


        if(a > b){
            swap(a, b);
        }
        if(a == 'a' && b == 'z'){
            return true;
        }
        return false;
    }
public:
    string resultingString(string s) {
        //get index of first consecutive pair
        if(s.size() == 1){
            return s;
        }

        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(res.empty() || !consec(res.back(), s[i])){
                res.push_back(s[i]);
            } else {
                res.pop_back();
            }
        }
        return res;

    }
};