class Solution {
    public boolean sumGame(String num) {
        int leftSum = 0;
        int rightSum = 0;
        int leftBlanks = 0;
        int rightBlanks = 0;
        for(int i = 0; i < num.length()/2; i++) {
            char c = num.charAt(i);
            if(c != '?') {
                leftSum += c - '0';

            } else {
                leftBlanks++;
            }
        }
        for(int i = num.length()/2; i < num.length(); i++) {
            char c = num.charAt(i);
            if(c != '?') {
                rightSum += c - '0';
            } else {
                rightBlanks++;
            }
        }

        if(leftBlanks + rightBlanks == 0) {
            return leftSum != rightSum;
        }

        if((leftBlanks + rightBlanks)%2 == 1){
            return true;
        }


        //alice increases the gap
        int remaining = Math.abs(leftBlanks - rightBlanks);

        

        if(remaining % 2 == 1) {
            return true;
        }
        int diff = Math.abs(leftSum - rightSum);
        if(remaining == 0) {
            return diff != 0;
        }
        if(leftBlanks > rightBlanks) {
            if(leftSum > rightSum) {
                return true;
            }
        } else if(rightBlanks > leftBlanks) {
            if(rightSum > leftSum) {
                return true;
            }
        }

        return diff != 9 * remaining/2;


    }
}