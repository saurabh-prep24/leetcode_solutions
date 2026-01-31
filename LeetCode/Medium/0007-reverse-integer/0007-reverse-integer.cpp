class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int d = x % 10;
            // check for 10*rev > INT_MAX or 10*rev < INT_MIN
            // but instead of multiply we can do divide to avoid interger
            // overflow no need to add digit as digit < 10 so only division by
            // 10 can handle overflow
            if (rev > (INT_MAX) / 10 || rev < (INT_MIN) / 10)
                return 0;

            // update rev
            rev = 10 * rev + d;
            x /= 10;
        }
        return rev;
    }
};