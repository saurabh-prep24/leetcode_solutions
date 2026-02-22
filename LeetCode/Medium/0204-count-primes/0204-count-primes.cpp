class Solution {
public:
    // time: O(N*N)
    int simple(int n) {
        int a = 0;
        if (n < 3) {
            return 0;
        }
        if (n == 3)
            return 1;

        // loop for all
        for (int i = 2; i < n; i++) {
            bool isPrime = 1;
            // check prime starting div from 2 to sqrt(n)
            for (int j = 2; j * j <= i; j++) {
                // if any divisor found - non-prime
                if (i % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
            // update prime count
            if (isPrime) {
                a++;
            }
        }
        // return ans
        return a;
    }

    // time: O(N log log N)
    // space: O(N)
    int sieve(int n) {
        if (n < 3) {
            return 0;
        }
        // store prime - sieve
        vector<bool> prime(n, 1);
        prime[0] = prime[1] = 0; // 0, 1 - non-prime

        int a = 0; // considering 2 as prime

        // loop all upto n
        for (int i = 2; i < n; i++) {
            // if prime then update ans
            // process mutiples as non-primes
            if (prime[i]) {
                a++;
                // make all mutiples of i from i*i to n as non-prime
                for (long long j = 1LL * i * i; j < n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        // return ans
        return a;
    }

    // time: O(N log log N) - better than normal as even computation are skipped
    // space: O(N)
    int sieveOpt(int n) {
        if (n < 3) {
            return 0;
        }
        // prime vector
        vector<bool> prime(n, 1);
        prime[0] = prime[1] = 0; // 0,1 - non-prime

        int a = 1; // considering 2 as prime

        // loop all odd mutiples only
        for (int i = 3; i * i <= n; i += 2) {
            // if curr is prime then
            // mark all odd mulitples as non-prime
            // from 3*i to n increamenting odd mutiplier - j+2*i [9, 15, 21 etc]
            if (prime[i]) {
                for (long long j = 1LL * 3 * i; j < n; j += 2 * i) {
                    prime[j] = 0;
                }
            }
        }

        // count all odd primes - even can't be prime other than 2 [started a=1]
        for (int i = 3; i < n; i += 2) {
            if (prime[i]) {
                a++;
            }
        }
        return a;
    }

    int countPrimes(int n) {
        // return simple(n);
        // return sieve(n);
        return sieveOpt(n);
    }
};