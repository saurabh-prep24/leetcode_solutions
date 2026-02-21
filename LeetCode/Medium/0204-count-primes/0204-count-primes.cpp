class Solution {
public:
    int simple(int n) {
        int a = 0;
        if (n < 3) {
            return 0;
        }
        if (n == 3)
            return 1;
        for (int i = 2; i < n; i++) {
            bool isPrime = 1;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
            if (isPrime) {
                a++;
            }
        }

        return a;
    }

    int sieve(int n) {
        if (n < 3) {
            return 0;
        }
        vector<bool> prime(n, 1);
        prime[0] = prime[1] = 0;
        int a = 0; // considering 2 as prime
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                a++;
                for (int j = i * i; j < n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        return a;
    }

    int countPrimes(int n) {
        // return simple(n);
        return sieve(n);
    }
};