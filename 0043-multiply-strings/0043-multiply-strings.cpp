class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        if(num1.size() < num2.size()){
            std::swap(num1, num2);
        }
        std::vector<int> ans(num1.size() + num2.size(), 0);
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());

        for(int i = 0; i < num1.size(); i++){
            for(int j = 0; j < num2.size(); j++){
                ans[i + j] += (num1[i] - '0') * (num2[j] - '0');
                ans[i + j + 1] += ans[i + j] / 10;
                ans[i + j] = ans[i + j] % 10;      
            }
        }

        std::reverse(ans.begin(), ans.end());
        int i = 0;
        while(ans[i] == 0){
            i++;
        }
        string strAns(ans.size() - i, '.');
        for(int j = 0; j < strAns.size(); j++){
            strAns[j] = ans[i + j] + '0';
        }

        return strAns;

    
    }
    
};
