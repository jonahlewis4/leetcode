class Solution {

    static int bit2(int byte) {
        return (byte& (128 + 64)) >> 6;
    }
    static int bit5(int byte) {
        return (byte& (128 + 64 + 32 + 16 + 8)) >> 3;
    }
public:
    bool validUtf8(vector<int>& data) {
        int i = 0;

        const auto checkNAhead = [&data](int& i, int max) {
            for(int j = 0; j < max; j++) {
                i++;
                if(i >= data.size()) {
                    return false;
                } 

                int two = bit2(data[i]);
                if((two ^ (0 + 2)) != 0){
                    return false;
                }
            }
            i++;
            return true;
        };
        while(i < data.size()) {
            int byte = data[i];
            int first5 = bit5(byte);
            
            if((first5 ^ (0 + 2 + 4 + 8 + 16)) == 0){
                //parse next 3 bytes for 10
                bool check = checkNAhead(i, 3);
                if(!check) {
                    return false;
                }
                
            } else if (((first5>>1)^(0 + 2 + 4 + 8)) == 0){
                //parse next 2 bytes for 10
                bool check = checkNAhead(i, 2);
                if(!check) {
                    return false;
                }
            } else if (((first5>>2)^(0 + 2 + 4))==0){
                //parse next byte for 10
                bool check = checkNAhead(i, 1);
                if(!check) {
                    return false;
                }
            } else if (((first5>>4)^(0))==0){
                i++;
            } else {
                return false;
            }
        }        

        return true;
    }
};