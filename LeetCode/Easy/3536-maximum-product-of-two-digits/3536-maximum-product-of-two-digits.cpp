class Solution {
public:
    int maxProduct(int n) {
        int max1 = INT_MIN, max2 = INT_MIN;
        while (n) {
            int d = n % 10;
            if (max1 == INT_MIN) {
                max1 = d;
            } else if (d > max1) {
                max2 = max1;
                max1 = d;
            } else if (d > max2) {
                max2 = d;
            }
            n /= 10;
        }
        // cout << max1 << " " << max2 << endl;
        return max1 * max2;
    }
};