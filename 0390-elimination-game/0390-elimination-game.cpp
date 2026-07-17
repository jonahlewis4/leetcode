class Solution {
public:
    int lastRemaining(int n) {
        if(n == 1) {
            return 1;
        }
        if(n == 2) {
            return 2;
        }
        //1 3 5 7 9
        //8 4
        //2


        //1 2 3 4 5 6 7 8 9 10 11
        //1 3 5 7 9 11 -> 2 4 6 8 10
        //10 6 2 -> 4 8
        //4 -> 8


        //1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
        //1 3 5 7 9 11 13 15 17 19 -> 2 4 6 8 10 12 14 16 18 20
        //20 16 12 8 4 -> 2 6 10 14 18
        //2 10 18 -> 6 14
        //14 -> 6  


        int gap = 2;
        int remaining = n;
        int leftBoundary = 1;
        int rightBoundary = n;
        // cout<<"leftBoundary: "<<leftBoundary<<endl;
        // cout<<"rightBoundary: "<<rightBoundary<<endl;
        // cout<<"remaining: "<<remaining<<endl;
        // cout<<"__________________"<<endl;
        while(true) {
            //go left to right

            //if rightBoundary marked for deletion, move that too
            
            int deletions = (rightBoundary - leftBoundary)/gap + 1;
            remaining -= deletions;
            
            if((rightBoundary - leftBoundary)%gap == 0){
                rightBoundary -= gap/2;
            }

            leftBoundary += gap/2;

            gap *= 2;
            // cout<<"moved right, boundary is "<<endl;
            // cout<<"leftBoundary: "<<leftBoundary<<endl;
            // cout<<"rightBoundary: "<<rightBoundary<<endl;
            // cout<<"remaining: "<<remaining<<endl;
            // cout<<"__________________"<<endl;

            if(remaining <= 2) {
                if(remaining == 1) {
                    return rightBoundary;
                }
                return leftBoundary;
            }

            

            //go right to left

            deletions = (rightBoundary - leftBoundary)/gap + 1;
            remaining -= deletions;

            if((rightBoundary - leftBoundary)%gap == 0) {
                leftBoundary += gap/2;
            }
            rightBoundary -= gap/2;
            
            // cout<<"moved left, boundary is "<<endl;
            // cout<<"leftBoundary: "<<leftBoundary<<endl;
            // cout<<"rightBoundary: "<<rightBoundary<<endl;
            // cout<<"remaining: "<<remaining<<endl;
            // cout<<"__________________"<<endl;
            gap *= 2;

            if(remaining <= 2) {
                if (remaining == 1) {
                    return leftBoundary;//last value
                }
                //return right value
                return rightBoundary;
            }

            
        }

        return 0;
    }
};