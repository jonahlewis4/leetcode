class Solution {

private:
    
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> events(nums.size() + 1);
        int sum = 0;
        int qI = 0;
        for(int i = 0; i < nums.size() ; i++) {
            //if sum is smaller than nums[i] 
            //we must increase sum until it is.
            sum += events[i];

            while(qI < queries.size() && sum < nums[i]){
                int qBegin = queries[qI][0];
                int qEnd = queries[qI][1];
                int qDecrease = queries[qI][2];

                if(qBegin > i){
                    events[qBegin] += qDecrease;
                    events[qEnd + 1] -= qDecrease;
                } else {
                    //if the start of the query is
                    //before or equal to the 
                    //current index we need to 
                    //handle its change

                    //if it ends before current index
                    //the query isn't in effect 
                    //on this sum, do nothing.

                    //this means we only 
                    //do something if it ends
                    //at or after current index

                    if(qEnd >= i) {
                        //if we get to this point
                        //the query starts
                        //before here
                        //and it is included
                        //which means we need
                        //to increase current
                        //sum by the query 
                        //decrease amount
                        sum += qDecrease;
                        events[qEnd + 1] -= qDecrease;
                    }
                }
                
                qI++;
            }

            if(qI >= queries.size() && sum < nums[i]){
                return -1;
            }
        }

        return qI;
    }
};