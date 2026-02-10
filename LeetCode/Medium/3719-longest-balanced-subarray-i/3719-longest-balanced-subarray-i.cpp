class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0, n = nums.size();
        set<int> odd;
        set<int> even;
        for (int j = 0; j < n - 1; j++) {
            for (int i = j; i < n; i++) {
                if (nums[i] % 2 == 0) {
                    even.insert(nums[i]);
                } else {
                    odd.insert(nums[i]);
                }
                if (even.size() == odd.size()) {
                    // cout << j << " " << i << " " << i - j + 1 << endl;
                    ans = max(ans, i - j + 1);
                }
            }
            odd.clear();
            even.clear();
        }
        return ans;
    }
};