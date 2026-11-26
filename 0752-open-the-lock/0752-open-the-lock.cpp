class Solution {
public:
    int openLock(vector<string>& deadends, const string& target) {

        unordered_set<int> visited;
        for(const string& end : deadends) {
            visited.insert(stoi(end));
        }


        if(visited.contains(0)){
            return -1;
        }


        int targetInt = stoi(target);
        if(targetInt == 0) {
            return 0;
        }


       

        queue<int> q;
        q.push(0);

        for(int i = 0; !q.empty(); i++) {
            int n = q.size();
            for(int j = 0; j < n; j++) {
                int pow = 1;
                int num = q.front();
                
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int digit = num % (pow * 10) / pow;

                    int increaseDigit = (digit + 1) % 10;
                    int decreaseDigit = ((digit - 1) + 10) % 10;

                    int numLessDigit = num - digit * pow;

                    int increasedNum = numLessDigit + increaseDigit * pow;
                    int decreasedNum = numLessDigit + decreaseDigit * pow;

                    if(!visited.contains(increasedNum)) {
                        if(increasedNum == targetInt) {
                            return i+1;
                        }
                        visited.insert(increasedNum);
                        q.push(increasedNum);

                    }
                    if(!visited.contains(decreasedNum)) {
                        if(decreasedNum == targetInt) {
                            return i + 1;
                        }
                        visited.insert(decreasedNum);
                        q.push(decreasedNum);
                    }
                    pow *= 10;

                }
            }
        }

        return -1;
    }
};