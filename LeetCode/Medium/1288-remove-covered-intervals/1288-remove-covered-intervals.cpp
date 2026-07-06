class Solution {
public:
    // time: O(n*logn)
    // space: O(n)
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
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
};