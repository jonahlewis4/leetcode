class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(const string& op : operations) {
            switch(op.front()){
                case '+':{
                    x++;
                    break;
                }
                case '-':{
                    x--;
                    break;
                }
            }

            switch(op.back()){
                 case '+':{
                    x++;
                    break;
                }
                case '-':{
                    x--;
                    break;
                }
            }
        }
        return x;
    }
};