
class Solution {
public:
    int cost(int x) { return x > 0; }

    void recBrute(vector<vector<int>>& grid, int& k, int n, int m, int x, int y,
                  int currScore, int currCost, int& maxScore) {

        currScore += grid[x][y];
        currCost += cost(grid[x][y]);

        if (currCost > k)
            return;

        // destination
        if (x == n - 1 && y == m - 1) {
            maxScore = max(maxScore, currScore);
            return;
        }

        // right
        if (y + 1 < m) {
            recBrute(grid, k, n, m, x, y + 1, currScore, currCost, maxScore);
        }

        // down
        if (x + 1 < n) {
            recBrute(grid, k, n, m, x + 1, y, currScore, currCost, maxScore);
        }
    }

    int recSolve(vector<vector<int>>& grid, int k, int n, int m, int x, int y) {
        if (x >= n || y >= m) {
            return -1;
        }
        if (cost(grid[x][y]) > k) {
            return -1;
        }
        if (x == n - 1 && y == m - 1) {
            return grid[x][y];
        }

        int right = recSolve(grid, k - cost(grid[x][y]), n, m, x, y + 1);
        int down = recSolve(grid, k - cost(grid[x][y]), n, m, x + 1, y);
        int maxi = max(right, down);
        if (maxi == -1) {
            return -1;
        }
        return grid[x][y] + maxi;
    }

    int recSolveMemo(vector<vector<int>>& grid, int k, int x, int y, int n,
                     int m, vector<vector<vector<int>>>& dp) {
        // invalid
        if (x >= n || y >= m) {
            return -1;
        }

        int c = cost(grid[x][y]);
        if (c > k)
            return -1;

        if (x == n - 1 && y == m - 1) {
            // score at last cell
            return dp[x][y][k] = grid[x][y];
        }

        // already calc so return
        if (dp[x][y][k] != INT_MIN) {
            return dp[x][y][k];
        }

        // move right
        int right = recSolveMemo(grid, k - c, x, y + 1, n, m, dp);
        // move down
        int down = recSolveMemo(grid, k - c, x + 1, y, n, m, dp);
        // get max score
        int maxi = max(right, down);
        // if -1 then return
        if (maxi == -1) {
            return dp[x][y][k] = -1;
        }
        // add curr score in maxi
        return dp[x][y][k] = grid[x][y] + maxi;
    }

    int recSolveTab(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        for (int x = n - 1; x >= 0; x--) {
            for (int y = m - 1; y >= 0; y--) {
                for (int c = 0; c <= k; c++) {
                    // cost > curr cost (c)
                    if (cost(grid[x][y]) > c) {
                        continue;
                    }

                    // final cell
                    if (x == n - 1 && y == m - 1) {
                        // score at last cell
                        dp[x][y][c] = grid[x][y];
                        continue;
                    }

                    int right = -1, down = -1;
                    // rem cost
                    int rem = c - cost(grid[x][y]);
                    if (y + 1 < m) {
                        // move right
                        right = dp[x][y + 1][rem];
                    }
                    if (x + 1 < n) {
                        // move down
                        down = dp[x + 1][y][rem];
                    }
                    // get max score
                    int maxi = max(right, down);
                    // if -1 then continue else update
                    if (maxi != -1) {
                        // add curr score in maxi
                        dp[x][y][c] = grid[x][y] + maxi;
                    }
                }
            }
        }
        return dp[0][0][k];
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        // int ans = -1;
        // int n = grid.size(), m = grid[0].size();
        // recBrute(grid, k, n, m, 0, 0, 0, 0, ans);
        // return ans;

        // int ans = -1;
        // int n = grid.size(), m = grid[0].size();
        // ans = recSolve(grid, k, n, m, 0, 0);
        // return ans;

        // int n = grid.size(), m = grid[0].size();
        // vector<vector<vector<int>>> dp(
        //     n, vector<vector<int>>(m, vector<int>(k + 1, INT_MIN)));
        // int ans = recSolveMemo(grid, k, 0, 0, n, m, dp);
        // return ans != INT_MIN ? ans : -1;

        return recSolveTab(grid, k);
    }
};