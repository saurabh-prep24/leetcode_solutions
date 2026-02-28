class Solution {
public:
    bool isPalindrome(int x) {
        // if x < 0 or x is 10 mutiple then can't be palidrome
        if (x < 0 || (x % 10 == 0 && x > 0))
            return false;

        // calc rev of x
        long long rev = 0;
        // store x
        int orig = x;
        // reverse
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        // ture if both eq
        if (rev == orig) {
            return true;
        }

        return false;
    }
};