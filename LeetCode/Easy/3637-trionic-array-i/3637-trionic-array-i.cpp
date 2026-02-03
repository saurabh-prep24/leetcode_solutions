class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 1, n = nums.size();
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        int p = i - 1;
        if (p == 0 || p == n - 1)
            return 0;

        while (i < n && nums[i - 1] > nums[i]) {
            i++;
        }
        int q = i - 1;
        if (q == p || q == n - 1)
            return 0;

        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }

        if (i == n && 0 < p && p < q && q < n - 1)
            return 1;
        else
            return 0;
    }
};