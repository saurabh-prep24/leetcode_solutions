class Solution {
public:
    // time: O(n*m)
    // space: O(1)
    int brute(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int i = n1 - 1;
        while (i >= 0) {
            int j = i;
            while (j < n2 && nums1[i] <= nums2[j]) {
                j++;
            }
            ans = max(ans, j - 1 - i);
            // cout << nums1[i] << " " << nums2[j] << " " << ans << endl;
            i--;
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int key) {
        int s = 0, e = nums.size() - 1, ans = -1;
        while (s <= e) {
            int m = (s + e) / 2;

            if (nums[m] >= key) {
                ans = m;
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return ans;
    }

    // time: O(n log n)
    // space: O(1)
    int opt(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int i = n1 - 1;
        while (i >= 0) {
            // upper bound - O(logn) instead of o(n) linear
            int j = upperBound(nums2, nums1[i]);
            if (j != -1) {
                ans = max(ans, j - i);
                // cout << nums1[i] << " " << nums2[j] << " " << ans << endl;
            }
            i--;
        }
        return ans;
    }

    // loop to end with condition
    // time: O(n)
    int best(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                j++;
            } else {
                i++;
                // dont start j = i every time as it would be o(n*n)
                // keep j there only for max ans only move j
                // when its behind i otherwise move j backward will
                // not give max ans for (j-i) after doing i++
                if(j<i)
                    j = i;
            }
        }
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // return brute(nums1, nums2);
        // return opt(nums1, nums2);
        return best(nums1, nums2);
    }
};