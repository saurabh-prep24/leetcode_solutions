class Solution {
public:
    // time: O(n*logn)
    // space: O(n)
    int solve1(vector<vector<int>>& intervals) {
        // sort by start time
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        // track prev intervals
        stack<pair<int, int>> prevInterval;
        // push intial duration
        prevInterval.push({intervals[0][0], intervals[0][1]});

        // check other intervals
        for (int i = 1; i < n; i++) {
            // curr interval
            int s = intervals[i][0];
            int e = intervals[i][1];

            // prevInterval
            int topS = prevInterval.top().first;
            int topE = prevInterval.top().second;

            // if prev is covered by curr - remove prev and push curr
            if (topS >= s && topE <= e) {
                prevInterval.pop();
                prevInterval.push({s, e});
            } else if (topS <= s && topE >= e) {
                // curr is covered by prev - nothing to do
                continue;
            } else {
                // partial overlap - push curr as well
                prevInterval.push({s, e});
            }
        }
        // return size as count of intervals
        return prevInterval.size();
    }

    struct Comp {
        bool operator()(vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return b[1] < a[1];
            }
            return a[0] < b[0];
        }
    };
    // time: O(n*logn)
    // space: O(1)
    int solveOpt(vector<vector<int>>& intervals) {
        // sort by start time and longer end time for same start time
        sort(intervals.begin(), intervals.end(), Comp());
        int n = intervals.size();

        // track end of interval
        int last = 0;
        int ans = 0;
        // check intervals
        for (int i = 0; i < n; i++) {
            // curr interval end
            int e = intervals[i][1];

            if (e > last) {
                ans++;
                last = max(last, e);
            }
        }
        return ans;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // return solve1(intervals);
        return solveOpt(intervals);
    }
};