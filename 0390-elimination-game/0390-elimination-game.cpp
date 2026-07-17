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


        int gap = 1;
        int remaining = n;
        int head = 1;
        int leftToRight = true;


        while(remaining > 1) {
            if(leftToRight || remaining % 2 == 1) {
                head += gap;
            }

            gap *= 2;
            remaining /= 2;

            leftToRight = !leftToRight;
        }

        return head;



        return 0;
    }
};