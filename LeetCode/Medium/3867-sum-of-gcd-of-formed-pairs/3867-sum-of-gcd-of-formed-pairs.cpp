class Solution {
public:
    long long gcd(long long a, long long b) {
        if (b == 0) {
            return a;
        }
        return a > b ? gcd(b, a % b) : gcd(a, b % a);
    }
    long long gcdSum(vector<int>& nums) {
        // curr maxi
        long long maxi = INT_MIN;
        // prefix gcd arr
        vector<long long> prefixGcd;
        
        for (auto i : nums) {
            // update maxi
            if (i > maxi) {
                maxi = i;
            }
            // store prefix gcd val
            prefixGcd.push_back(gcd(i, maxi));
        }

        // sort
        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int i = 0, j = prefixGcd.size() - 1;
        while (i < j) {
            // calc paired sum from each end
            ans += gcd(prefixGcd[j], prefixGcd[i]);
            i++;
            j--;
        }

        return ans;
    }
};