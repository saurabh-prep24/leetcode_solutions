class Solution {
public:
    int getRotDig(int d) {
        switch (d) {
        case 0:
            return d;
        case 1:
            return d;
        case 8:
            return d;
        case 2:
            return 5;
        case 5:
            return 2;
        case 6:
            return 9;
        case 9:
            return 6;
        default:
            return -1;
        }
        return -1;
    }
    bool isValidN(int n) {
        if (n < 10) {
            int rotDig = getRotDig(n);
            return rotDig != -1 && n != rotDig;
        }
        int rotDig = 0, m = 1;
        int t = n;
        while (n) {
            int d = n % 10;
            int r = getRotDig(d);
            if (r == -1)
                return 0;
            rotDig += m * r;
            n /= 10;
            m *= 10;
        }
        // cout << "getD: " << t << " " << rotDig << endl;
        return t != rotDig;
    }
    // time: O(N*logN)
    int brute(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            bool valid = isValidN(i);
            // cout << i << " " << valid << " " << ans << endl;
            if (valid) {
                ans++;
            }
        }
        return ans;
    }

    // time: O(N*logN)
    // no need to get retotate num
    // just check if its valid and any dig is changing present
    int bruteSimple(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            bool isValid = 1;
            bool hasChange = 0;
            int curr = i;
            while (curr) {
                int d = curr % 10;
                if (d == 3 || d == 4 || d == 7) {
                    isValid = 0;
                    break;
                } else if (d == 2 || d == 5 || d == 6 || d == 9) {
                    // dont break
                    // check for all dig are valid
                    hasChange = 1;
                }
                curr /= 10;
            }
            if (isValid && hasChange) {
                ans++;
            }
        }
        return ans;
    }

    int solveRec(int n) {
        if (n == 0 || n == 1)
            return 0;

        int rem = solveRec(n / 10);
        // if rem is invalid then return
        if (rem == -1)
            return -1;
        int d = n % 10;
        // any invalid then return false
        if (d == 3 || d == 4 || d == 7) {
            return -1;
        }
        // changing dig found so return true
        if (d == 2 || d == 5 || d == 6 || d == 9) {
            return 1;
        }
        // return prev val
        // as curr dig is same so return prev ans
        return rem;
    }
    int rec(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (solveRec(i) == 1) {
                ans++;
            }
        }
        return ans;
    }

    int solveRecDP(int n, vector<int>& dp) {
        if (n == 0 || n == 1)
            return dp[n] = 0;

        if (dp[n] != INT_MIN) {
            return dp[n];
        }
        int rem = solveRecDP(n / 10, dp);
        // if rem is invalid then return
        if (rem == -1)
            return dp[n] = -1;
        int d = n % 10;
        // any invalid then return false
        if (d == 3 || d == 4 || d == 7) {
            return dp[n] = -1;
        }
        // changing dig found so return true
        if (d == 2 || d == 5 || d == 6 || d == 9) {
            return dp[n] = 1;
        }
        // return prev val
        // as curr dig is same so return prev ans
        return dp[n] = rem;
    }
    int recDP(int n) {
        int ans = 0;
        vector<int> dp(n + 1, INT_MIN);
        for (int i = 1; i <= n; i++) {
            if (solveRecDP(i, dp) == 1) {
                ans++;
            }
        }
        return ans;
    }
    int rotatedDigits(int n) {
        // return brute(n);
        // return bruteSimple(n);
        // return rec(n);
        return recDP(n);
    }
};