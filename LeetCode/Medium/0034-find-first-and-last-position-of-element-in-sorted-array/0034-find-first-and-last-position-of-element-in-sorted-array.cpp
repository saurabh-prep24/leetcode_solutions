class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> pos(2, -1);

        int st = 0, end = nums.size() - 1;
        // For leftmost pos
        // store index whenever moving window to left part
        // and elem is same as target
        while (st <= end) {
            int m = st + (end - st) / 2;
            if (nums[m] >= target) {
                // update pos when matching target
                pos[0] = nums[m] == target ? m : -1;
                end = m - 1;
            } else {
                st = m + 1;
            }
        }
        st = 0;
        end = nums.size() - 1;

        // for rightmost pos
        // store pos whenever move to right side part
        while (st <= end) {
            int m = st + (end - st) / 2;
            if (nums[m] <= target) {
                // update pos when matching target
                pos[1] = nums[m] == target ? m : -1;
                st = m + 1;
            } else {
                end = m - 1;
            }
        }
        // cout << pos[0] << pos[1] << endl;

        return pos;
    }
};