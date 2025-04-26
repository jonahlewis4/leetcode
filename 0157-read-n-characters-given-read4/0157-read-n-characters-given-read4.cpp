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
        int numRead = 0;
        bool eOF = false;
        char* bufStart = buf;
        while(!eOF && numRead < n){
            int incoming = read4(buf);
            if(incoming < 4){
                eOF = true;
            }
            numRead += incoming;
            buf += incoming;
        }
        if(n < numRead){
            buf[n] = '\0';
        }
        return min(numRead, n);
    }
};