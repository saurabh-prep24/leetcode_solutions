class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(), arr.end());

        int mid = arr.size() / 2;
        int ans = 0;
        int i = mid - 1, j = mid + 1;
        while (i >= 0) {
            int diff = arr[mid] - arr[i];
            if (diff % x == 0) {
                ans += diff / x;
            } else {
                return -1;
            }
            i--;
        }

        while (j < arr.size()) {
            int diff = arr[j] - arr[mid];
            if (diff % x == 0) {
                ans += diff / x;
            } else {
                return -1;
            }
            j++;
        }
        return ans;
    }
};