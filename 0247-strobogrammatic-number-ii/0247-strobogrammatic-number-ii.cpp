class Solution {
    vector<string> res;
    string temp = "";
public:
    vector<string> findStrobogrammatic(int n) {
        if(n % 2 == 1){
            temp = string(n, '.');
            int mid = n / 2;

            temp[mid] = '0';
            strobe(mid - 1);

            temp[mid] = '1';
            strobe(mid - 1);

            temp[mid] = '8';
            strobe(mid - 1);

        } else {
            int mid = n / 2 - 1;
            temp = string(n, '.');
            strobe(mid);
        }

        return res;
    }

    void strobe(int i){
        if(i < 0){
            res.push_back(temp);
            return;
        }

        int other = temp.size() - i - 1;

        temp[i] = '1';
        temp[other] = '1';
        strobe(i - 1);

        temp[i] = '6';
        temp[other] = '9';
        strobe(i - 1);

        temp[i] = '9';
        temp[other] = '6';
        strobe(i - 1);

        temp[i] = '8';
        temp[other] = '8';
        strobe(i - 1);

        if(i != 0) {
            temp[i] = '0';
            temp[other] = '0';
            strobe(i - 1);
        }
    }
};