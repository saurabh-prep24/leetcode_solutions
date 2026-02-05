class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int curr = nums[i] % n;
            if (nums[i] == 0) {
                ans[i] = nums[i];
            } else if (nums[i] > 0) {
                ans[i] = nums[(i + curr) % n];
                // cout << i << curr << " " << (i + curr) % n << endl;
            } else {
                ans[i] = nums[(i + n - abs(curr)) % n];
                // cout << i << curr << " " << (i + n - abs(curr)) % n << endl;
            }
        }
        return ans;
    }
};