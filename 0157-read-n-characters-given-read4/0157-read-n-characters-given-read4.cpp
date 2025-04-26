/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int totalRead = 0;
        char readBuffer[4];
        bool isEOF = false;
        while(totalRead < n && !isEOF){
            int amountRead = read4(readBuffer);
            if(amountRead < 4){
                isEOF = true;
            }

            for(int i = 0; i < amountRead; i++){
                if(totalRead == n){
                    break;
                }
                *(buf + totalRead) = *(readBuffer + i);
                totalRead++;
            }
        }

        return totalRead;
    }
};