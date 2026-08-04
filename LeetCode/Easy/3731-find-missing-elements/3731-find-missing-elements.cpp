class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 1) {
            return {};
        }
        int start = nums[0], end = nums[n - 1];
        int j = 0;
        for (int i = start; i <= end; i++) {
            if (nums[j] == i) {
                j++;
            } else {
                ans.push_back(i);
            }
        }
        return ans;
    }
};