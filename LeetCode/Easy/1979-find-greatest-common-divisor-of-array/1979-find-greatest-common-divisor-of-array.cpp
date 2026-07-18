class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }

        return gcd(b, a % b);
    }
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX, maxi = 0;
        for (auto i : nums) {
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        return gcd(maxi, mini);
    }
};