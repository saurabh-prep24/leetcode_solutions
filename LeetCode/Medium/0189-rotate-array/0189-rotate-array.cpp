class Solution {
public:
    void rotateRightOnce(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return;
        }
        int last = nums[n - 1];
        for (int i = n - 1; i > 0; i--) {
            nums[i] = nums[i - 1];
        }
        nums[0] = last;
    }
    // time: O(N*K)
    // space: O(1)
    void rotateUptoK(vector<int>& nums, int k) {
        while (k--) {
            rotateRightOnce(nums);
        }
    }

    // time: O(n)
    // space: O(n)
    void rotateTempCopy(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        vector<int> temp(n);

        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }

        nums = temp;
    }

    // time: O(n)
    // space: O(k) - lesser space than above
    void copyToRotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rem;

        // copy last n-k elem to rem so later we can copy to front
        for (int i = n - k; i < n; i++) {
            rem.push_back(nums[i]);
        }

        // move starting k elem to forward by k places
        for (int i = n - 1; i - k >= 0; i--) {
            nums[i] = nums[i - k];
        }

        // move last n-k elem to front
        for (int i = 0; i < rem.size(); i++) {
            nums[i] = rem[i];
        }
    }

    // time: O(n)
    // space: O(1)
    void arrInverse(vector<int>& nums, int k) {
        // [1 2 3 4 5]
        // k = 3
        // [3 4 5 1 2]
        // a = [1 2] | b = [3 4 5]
        // ab - given | ba - needed
        // reverse full arr
        // reverse [0, k] then [k+1, n]
        // [5 4 3 2 1]
        // [3 4 5][1 2] - ans
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    void juglingRotate(vector<int>& nums, int k) {
        // break arr into groups of k
        // then replace all elem to next group with cyclic arr
        int n = nums.size();
        int grps = n % 2 == 0 ? n / k : n / k + 1;
        for (int iter = 0; iter < grps; i++) {
            for (int i = 0; i < k; i++) {
                int first = nums[i];
            }
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // rotateUptoK(nums, k);
        // copyToRotate(nums, k);
        // rotateTempCopy(nums, k);
        arrInverse(nums, k);
    }
};