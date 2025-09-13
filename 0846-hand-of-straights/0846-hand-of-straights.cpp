class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> count;
        for(const int i : hand) {
            count[i]++;
        }

        for(int i : hand) {
            //go left till left is 0
            int ogI = i;
            while(count[i - 1] != 0) {
                i--;
            }

            //crawlcheck til back at value and empty
            while(count[ogI] != 0) {
                while(count[i] != 0) {
                    for(int j = i; j < i + groupSize; j++) {
                        if(count[j]-- == 0){
                            return false;
                        }
                    }
                }
                i++;

            }
        }

        return true;

    }
};