class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int gcdOfOddEvenSums(int n) {
        int sumEven = 0, sumOdd = 0;
        // AP sum:
        // a + a+d + a+2d + a+(n-1)d
        // na + d(n-1)n/2
        // n(a+(n-1)d/2)
        // n/2(a + a+(n-1)d)
        // n(a+l)/2 [l=a+(n-1)d]
        sumEven = (n * (2 + 2 + (n - 1) * 2)) / 2;
        sumOdd = (n * (1 + 1 + (n - 1) * 2)) / 2;
        return sumEven > sumOdd ? gcd(sumEven, sumOdd) : gcd(sumOdd, sumEven);
    }
};