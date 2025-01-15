class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;

        int r = 0;

        int count = 0;
        while(r < chars.size()){
            count++;
            if(r + 1 >= chars.size() || chars[r + 1] != chars[r]){
                chars[i] = chars[r];
                i++;
                if(count > 1){
                    string countString = to_string(count);
                    for(int j = 0; j < countString.size(); j++){
                        chars[i] = countString[j];
                        i++;
                    }
                }
                count = 0;

            }
            r++;
        }
        return i;
        
    }
};