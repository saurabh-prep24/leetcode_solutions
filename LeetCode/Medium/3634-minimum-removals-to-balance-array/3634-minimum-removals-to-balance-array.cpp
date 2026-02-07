class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1)
            return 0;
        int i = 0, j = 0;
        int ans = 0;
        while (i < n && j < n) {
            if (nums[j] <= 1LL * k * nums[i]) {
                j++;
            } else {
                i++;
            }
            ans = max(ans, j - i);
            // cout << i << j << ans << endl;
        }
        return n - ans;
    }
};

// k=2
// 1 3 5 6 10 12