class Solution {
public:
    int getSumDigitsSquare(int n) {
        int sum = 0;
        while (n > 0) {
            int dig = n % 10;
            sum += dig * dig;
            n = n / 10;
        }
        // cout << sum;
        return sum;
    }
    // fast and slow ptr approach
    // O(log N)
    bool isHappy(int n) {
        int slow = getSumDigitsSquare(n);
        int fast = getSumDigitsSquare(getSumDigitsSquare(n));
        while (slow != fast) {
            if (fast == 1)
                return 1;
            slow = getSumDigitsSquare(slow);
            fast = getSumDigitsSquare(getSumDigitsSquare(fast));
        }
        return slow == 1;
    }
};