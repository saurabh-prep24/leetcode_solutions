class Solution {
public:
    bool rec(string& s, int& minJump, int& maxJump, int i) {
        int n = s.size();
        if (i == n - 1) {
            return 1;
        }
        if (i > n - 1) {
            return 0;
        }
        int start = i + minJump;
        int last = min(i + maxJump, n - 1);
        for (int j = last; j >= start; j--) {
            if (s[j] == '0') {
                bool currAns = rec(s, minJump, maxJump, j);
                if (currAns)
                    return currAns;
            }
        }
        return 0;
    }

    // time: O(n*(maxJump-minJump)) ~ O(n*n)
    bool recMemo(string& s, int& minJump, int& maxJump, int i,
                 vector<int>& dp) {
        int n = s.size();
        if (i == n - 1) {
            return 1;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int start = i + minJump;
        int last = min(i + maxJump, n - 1);
        for (int j = last; j >= start; j--) {
            if (s[j] == '0') {
                bool currAns = recMemo(s, minJump, maxJump, j, dp);
                if (currAns) {
                    return dp[i] = 1;
                }
            }
        }
        return dp[i] = 0;
    }

    // time: O(n*(maxJump-minJump)) ~ O(n*n)
    bool tab(string& s, int& minJump, int& maxJump) {
        int n = s.size();
        vector<int> dp(s.size() + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                dp[i] = 1;
                continue;
            }

            int start = i + minJump;
            int last = min(i + maxJump, n - 1);
            for (int j = last; j >= start; j--) {
                if (s[j] == '0') {
                    bool currAns = dp[j];
                    if (currAns) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }

    // time: O(n)
    // space: O(n)
    // use count as valid positions
    // count valid positions in window moving ahead
    // add new val as [i-minJump]
    // remove old val as [i-maxJump-1]
    // if count > 0 and s[i] == 0 then its valid
    // return [n-1] as ans
    bool sliding(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> reach(n, 0);
        int count = 0;
        reach[0] = 1;
        for (int i = 1; i < n; i++) {
            // add new counts
            if (i - minJump >= 0) {
                count += reach[i - minJump];
            }
            // remove out of window counts
            if (i - maxJump - 1 >= 0) {
                count -= reach[i - maxJump - 1];
            }
            // if curr == 0 and count > 0. then its valid position
            if (count > 0 && s[i] == '0') {
                reach[i] = 1;
            }
        }
        return reach[n - 1] > 0;
    }
    bool canReach(string s, int minJump, int maxJump) {
        if (s[s.size() - 1] != '0') {
            return 0;
        }

        // rec
        // return rec(s, minJump, maxJump, 0);
        // vector<int> dp(s.size() + 1, -1);
        // return recMemo(s, minJump, maxJump, 0, dp);

        // return tab(s, minJump, maxJump);

        return sliding(s, minJump, maxJump);
    }
};