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
    void copyToRotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rem;

        // copy last n-k elem to rem so later we can copy to front
        for(int i = n-k;i<n;i++){
            rem.push_back(nums[i]);
        }

        // move starting k elem to forward by k places
        for(int i = n-1; i-k>=0 ; i--){
            nums[i] = nums[i-k];
        }

        // move last n-k elem to front
        for(int i = 0;i<rem.size();i++){
            nums[i] = rem[i];
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // rotateUptoK(nums, k);
        copyToRotate(nums, k);
    }
};