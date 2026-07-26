class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // ans will max of 
        // prod(max1,max2,max3) - all (+/-)ve
        // prod(min1, min2, max1) - both (+ and -)ve
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for (auto i : nums) {
            // track 2 min
            if (i <= min1) {
                min2 = min1;
                min1 = i;
            } else if (i < min2) {
                min2 = i;
            }

            // track 3 max
            if (i >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = i;
            } else if (i >= max2) {
                max3 = max2;
                max2 = i;
            } else if (i > max3) {
                max3 = i;
            }
        }

        // cout << max1 << max2 << max3 << endl;
        // cout << min1 << min2 << endl;

        int maxAns = max(max1 * max2 * max3, min1 * min2 * max1);
        return maxAns;
    }
};