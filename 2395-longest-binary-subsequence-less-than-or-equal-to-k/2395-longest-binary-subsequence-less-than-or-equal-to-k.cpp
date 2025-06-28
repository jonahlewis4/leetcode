class Solution {
public:
    int longestSubsequence(string s, int k) {
        int numDigits = lengthAsBinary(k);

        //select until the digit we're looking at is a 1 and is past numDigits, because any 1s before that are acceptable.

        //suppose the longest suffix is not the longest subsequence. 
        //then, that would be because we've selected a number to its left
        //which has more digits. WHen could this happen? If by picking zeroes
        //when we shouldn't, we can get a one in a further position than in k, but only by
        //at most 1 position because any 3 digit number is smaller than any 4 digit number.
        //Now, the shifting of the one could only happen if there are zeroes in k because
        //if k is all 1's, the 1 wouldn't exceed until the whole suffix was a larger size. 
        //But if k has 0's in it, any possible better version on the left would also have zeros in it
        //Those zeroes we can take for free, meaning the 1 smaller gets overwritten by this.



        //So, the algorithm is to 
        //start from the right and select 1s until :
        //from the right the 1's position is fruther than the lenght of k as a binary number
        //because that would for sure be too large.

        //if adding that one causes the value to become too large, we stop grabbing ones.
        //furutre zeroes on the left will work out.


        int runningSum = 0;
        int longest = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            int digit = s[i] - '0';
            if(digit == 0) {
                longest++;
            } else {
                int distFromRight = s.size() - i - 1;
                if(distFromRight + 1 > numDigits){
                    continue;
                } else if (runningSum + (1 << distFromRight) <= k) {
                    runningSum += (1 << distFromRight);
                    longest++;
                }

            }
        }

        return longest;
        
    }

    int lengthAsBinary(int num) const {
        return sizeof(num) * 8 - __builtin_clz(num);
    }
};