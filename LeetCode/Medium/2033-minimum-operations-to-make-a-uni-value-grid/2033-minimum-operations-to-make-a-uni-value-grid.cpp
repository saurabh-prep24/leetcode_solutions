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
        for (int i = 0; i < arr.size(); i++) {
            int diff = abs(arr[i] - arr[mid]);
            if (diff % x != 0) {
                return -1;
            }
            ans += diff / x;
        }
        return ans;
    }
};