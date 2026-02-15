class Solution {
public:
    int pivotInteger(int n) {
        int l = 1;
        int r = n;

        while(l <= r) {
            int m = l + (r - l) / 2;

            int leadingSum = (m * (m + 1))/2;
            int followingSum = (n * (n + 1))/2 - leadingSum + m;

            print(leadingSum, followingSum, m);

            if(leadingSum == followingSum) {
                return m;
            }

            if(leadingSum > followingSum) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return -1;
    }

    void print(int lead, int follow, int x) {
        cout<<"leading sum is "<<lead<<endl;
        cout<<"following sum is "<<follow<<endl;
        cout<<"x is "<<x<<endl;
        cout<<"_________________"<<endl;
    }
};