class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, m = 1;
        long long sum = 0;
        while (n) {
            int d = n % 10;
            if (d > 0) {
                sum += d;
                x = d * m + x;
                m *= 10;
            }
            n /= 10;
        }
        return x * sum;
    }
};