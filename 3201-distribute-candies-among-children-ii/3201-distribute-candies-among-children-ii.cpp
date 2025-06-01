class Solution {
public:
    long long distributeCandies(int n, int limit) {
        auto const & combinate = [](int x) -> long long {
            if(x <= 0) {
                return 0;
            }
            return (long long)x * (x - 1) / 2;

        };


        return combinate(n + 2) - 3 * combinate(n - (limit + 1) + 2) +  
        3 * combinate(n - 2 * (limit + 1) + 2) - combinate (n - 3 * (limit + 1) + 2);

    }
};