class Solution {
public:
    int sumDig(int n) {
        int s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    // time: O(N*log10^4)
    int brute(vector<int>& nums) {
        int miniSum = INT_MAX;
        for (auto i : nums) {
            miniSum = min(miniSum, sumDig(i));
        }
        return miniSum;
    }
    // time: O(n)
    int optSum(vector<int>& nums) {
        // 9999 = 9000 + 900 + 90 + 9
        // abcd = 1000a+100b+10c+1d
        // abcd = 999a+99b+9c + (a+b+c+d)
        // sum(n) = a+b+c+d
        // sum(n) = n - 9(111a+11b+1c)
        // sum(n) = n - 9(100a+10b+c + 10a+1b + a)
        // sum(n) = n - 9(n/10 + n/100 + n/1000)
        // [n/10 = abc] [n/100 = ab] [n/1000 = a]
        // using above sum can be solved in O(1)for fixed len ~ 10^4
        int ans = INT_MAX;
        for (auto i : nums) {
            int s = i - 9 * (i / 10 + i / 100 + i / 1000 + i / 10000);
            ans = min(ans, s);
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        // return brute(nums);
        return optSum(nums);
    }
};