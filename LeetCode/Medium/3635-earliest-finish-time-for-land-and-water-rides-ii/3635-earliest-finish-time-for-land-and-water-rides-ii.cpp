class Solution {
public:
    int calcDuration(int minFirstDuration, vector<int>& nextStart,
                     vector<int>& nextDuration) {
        int ans = INT_MAX;
        for (int i = 0; i < nextStart.size(); i++) {
            int d = max(minFirstDuration, nextStart[i]) + nextDuration[i];
            ans = min(ans, d);
        }
        return ans;
    }

    // time: O(n)
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int ans = INT_MAX;

        // start from land then water
        int earlyLandDuration = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            earlyLandDuration =
                min(earlyLandDuration, landStartTime[i] + landDuration[i]);
        }
        // calc duration for water next
        // for (int i = 0; i < waterStartTime.size(); i++) {
        //     int d =
        //         max(earlyLandDuration, waterStartTime[i]) + waterDuration[i];
        //     ans = min(ans, d);
        // }
        ans = min(ans, calcDuration(earlyLandDuration, waterStartTime,
                                    waterDuration));

        // start from water then land
        int earlyWaterDuration = INT_MAX;
        for (int i = 0; i < waterStartTime.size(); i++) {
            earlyWaterDuration =
                min(earlyWaterDuration, waterStartTime[i] + waterDuration[i]);
        }
        // calc duration for land next
        // for (int i = 0; i < landStartTime.size(); i++) {
        //     int d = max(earlyWaterDuration, landStartTime[i]) +
        //     landDuration[i]; ans = min(ans, d);
        // }
        ans = min(
            ans, calcDuration(earlyWaterDuration, landStartTime, landDuration));

        return ans;
    }
};