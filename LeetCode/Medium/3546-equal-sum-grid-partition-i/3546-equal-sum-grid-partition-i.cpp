class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long totalSum = 0;
        int n = grid.size();
        int m = grid[0].size();

        // get total sum
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                totalSum += grid[i][j];
            }
        }

        // odd total sum then 2 equal parts not possible
        if (totalSum % 2 != 0) {
            return 0;
        }

        // store rowSum and colSum in arr
        // vector<long long> rowSum(n, 0);
        // vector<long long> colSum(m, 0);

        // rowSum
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         rowSum[i] += grid[i][j];
        //     }
        // }

        // colSum
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         colSum[i] += grid[j][i];
        //     }
        // }

        // we dont really needed to store sum in arr as curr sum can be directly
        // used
        long long currSum = 0;
        long long targetSum = totalSum / 2;
        for (int i = 0; i < n; i++) {
            // currSum += rowSum[i];
            for (int j = 0; j < m; j++) {
                currSum += grid[i][j];
            }
            // half sum match found
            if (currSum == targetSum) {
                // cout << "row" << currSum << " " << totalSum << endl;
                return 1;
            } else if (currSum > targetSum) {
                // sum exceeding half then break as all elems>0
                break;
            }
        }

        currSum = 0;
        for (int i = 0; i < m; i++) {
            // currSum += colSum[i];

            for (int j = 0; j < n; j++) {
                currSum += grid[j][i];
            }
            // half sum match found
            if (currSum == targetSum) {
                // cout << "col" << currSum << " " << totalSum << endl;
                return 1;
            } else if (currSum > targetSum) {
                // sum exceeding half then break as all elems>0
                break;
            }
        }

        return 0;
    }
};