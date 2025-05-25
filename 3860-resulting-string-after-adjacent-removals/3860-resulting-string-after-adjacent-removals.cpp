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

        std::list<char> list;
        for(const auto & c : s){
            list.push_back(c);
        }

        using It = decltype(list.begin());

        It l = list.begin();
        It r = next(list.begin());  
        
        while(r != list.end()){
            if(consec(*l, *r)){
                It newL;
                It newR;
                if(l == list.begin()){
                    newL = next(r);
                    if(newL == list.end()){
                        newR = list.end();
                    } else {
                        newR = next(newL);
                    }
                } else {
                    newL = prev(l);
                    newR = next(r);
                }
                list.erase(l);
                list.erase(r);
                l = newL;
                r = newR;
            } else {
                l = next(l);
                r = next(r);
            }
        }
        string res = "";

        for(It itr = list.begin(); itr != list.end(); itr++){
            res.push_back(*itr);
        }

        return res;
    }
};