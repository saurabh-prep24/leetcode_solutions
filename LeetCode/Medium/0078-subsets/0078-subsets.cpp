class Solution {
public:
    void rec(int index, vector<int>& nums, vector<int> curr,
             vector<vector<int>>& subsets) {
        // end of nums
        // push curr to subsets and return
        if (index >= nums.size()) {
            subsets.push_back(curr);
            return;
        }

        // call without nums[index]
        rec(index + 1, nums, curr, subsets);
        // call with nums[index]
        curr.push_back(nums[index]);
        rec(index + 1, nums, curr, subsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        // fill up with recursion
        rec(0, nums, {}, subsets);
        // return filled subsets
        return subsets;
    }
};