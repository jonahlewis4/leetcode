class Solution {

struct iPair{
    int big;
    int bigIdx;

    int small = -1;
    int smallIdx = -1;
};
public:
    int maximumSwap(int num) {
        //2 7 3 6 

        //3 4 5 6

        //6 5 4 7

        //8 1 5 7 


        //solution: monotonic stack that only increases.
        //if we come across a smaller value, mark down index and value of smaller one
        
        stack<iPair> stk;

        int numCopy = num;
        int i = 0;
        while(numCopy > 0){
            int rightMostDigit = numCopy % 10;
            numCopy /= 10;
            
            if(stk.empty() || rightMostDigit > stk.top().big){
                stk.push({
                    .big = rightMostDigit,
                    .bigIdx = i,
                });
            }
            if(!stk.empty() && rightMostDigit < stk.top().big){
                stk.top().small = rightMostDigit;
                stk.top().smallIdx = i;
            }
            i++;
        }

        bool doTheSwap = false;
        iPair p;
        while(!stk.empty()){
            if(!doTheSwap && stk.top().small != -1){
                doTheSwap = true;
                p = stk.top();
            }
            stk.pop();
        }


        if(!doTheSwap){
            return num;
        }

        i = 0;
        int res = 0;
        int factor = 1;
        while(num > 0){
            int numToAdd = 0;
            if(i == p.bigIdx){
                numToAdd = p.small;
            } else if(i == p.smallIdx){
                numToAdd = p.big;
            } else {
                numToAdd = num % 10;
            }
            res += numToAdd * factor;
            factor *= 10;
            num /= 10;
            i++;
        }

        return res;

    }
};