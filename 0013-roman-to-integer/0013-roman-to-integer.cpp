class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        for(auto itr = s.begin(); itr != s.end(); ++itr){
            switch(*itr){
                case 'I':
                    if(itr + 1 != s.end() && *(itr + 1) == 'V'){
                        total += 4;
                        itr+=1;
                    }
                    else if(itr + 1 != s.end() && *(itr + 1) == 'X'){
                        total += 9;
                        itr+=1;
                    }
                    else total += 1;
                    break;
                case 'V':
                    total += 5;
                    break;
                case 'X':
                    if(itr + 1 != s.end() && *(itr + 1) == 'L'){
                        total += 40;
                        itr+=1;
                    }
                    else if(itr + 1 != s.end() && *(itr + 1) == 'C'){
                        total += 90;
                        itr+=1;
                    }
                    else total += 10;
                    break;
                case 'L':
                    total += 50;
                    break;
                case 'C':
                    if(itr + 1 != s.end() && *(itr + 1) == 'D'){
                        total += 400;
                        itr+=1;
                    }
                    else if(itr + 1 != s.end() && *(itr + 1) == 'M'){
                        total += 900;
                        itr+=1;
                    }
                    else total += 100;
                    break;
                case 'D':
                    total += 500;
                    break;
                case 'M':
                    total += 1000;
                    break;
                    
                    

            }
        }
        return total;
    }
};