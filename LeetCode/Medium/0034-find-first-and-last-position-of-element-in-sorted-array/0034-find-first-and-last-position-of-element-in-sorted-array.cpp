class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> pos(2, -1);

        int st = 0, end = nums.size() - 1;
        while (st <= end) {
            int m = st + (end - st) / 2;
            if (nums[m] >= target) {
                pos[0] = nums[m] == target ? m : -1;
                end = m - 1;
            } else {
                st = m + 1;
            }
        }
        st = 0;
        end = nums.size() - 1;
        while (st <= end) {
            int m = st + (end - st) / 2;
            if (nums[m] <= target) {
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