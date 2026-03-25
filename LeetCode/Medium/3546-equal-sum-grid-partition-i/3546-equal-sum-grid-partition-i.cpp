class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long totalSum = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> rowSum(n, 0);
        vector<long long> colSum(m, 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                totalSum += grid[i][j];
            }
        }

        // rowSum
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowSum[i] += grid[i][j];
            }
        }

        // colSum
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                colSum[i] += grid[j][i];
            }
        }

        long long currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum += rowSum[i];
            if (2 * currSum == totalSum) {
                // cout << "row" << currSum << " " << totalSum << endl;
                return 1;
            } else if (2 * currSum > totalSum) {
                break;
            }
        }

        currSum = 0;
        for (int i = 0; i < m; i++) {
            currSum += colSum[i];
            if (2 * currSum == totalSum) {
                // cout << "col" << currSum << " " << totalSum << endl;
                return 1;
            } else if (2 * currSum > totalSum) {
                break;
            }
        }

        return 0;
    }
};