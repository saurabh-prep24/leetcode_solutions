class Solution {
public:
    int getSetBitsCount(int n) {
        int s = 0;
        while (n > 0) {
            s += n & 1;
            n = n >> 1;
        }
        return s;
    }
    bool isPrime(int n) {
        if (n < 2)
            return 0;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return 0;
        }
        return 1;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int setBits = getSetBitsCount(i);
            if (isPrime(setBits)) {
                ans++;
                // cout << i << " " << setBits << " " << ans << endl;
            }
        }
        return ans;
    }
};