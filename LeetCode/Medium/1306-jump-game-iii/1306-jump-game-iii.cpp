class Solution {
public:
    bool rec(vector<int>& arr, int start, vector<bool>& vis) {
        if (start < 0 || start >= arr.size()) {
            return 0;
        }
        // return if already vis
        if (vis[start]) {
            return 0;
        }

        // mark vis
        vis[start] = 1;

        // return if 0
        if (arr[start] == 0) {
            return 1;
        }
        // return ans
        return rec(arr, start + arr[start], vis) ||
               rec(arr, start - arr[start], vis);
    }
    bool canReach(vector<int>& arr, int start) {
        // track vis
        vector<bool> vis(arr.size(), 0);
        return rec(arr, start, vis);
    }
};