class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        for (int k = n + m - 1; k >= 0; k--) {
            // check for larger elem and put it at end
            if (i >= 0 && j >= 0 && nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i--];
            } else if (j >= 0) {
                // process all nums2 elem otherwise
                nums1[k] = nums2[j--];
            }
        }
    }
};