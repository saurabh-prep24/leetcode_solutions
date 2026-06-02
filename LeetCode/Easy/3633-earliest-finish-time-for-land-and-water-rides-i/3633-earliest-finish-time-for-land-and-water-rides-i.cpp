class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ans = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {
                // Land->Water
                int d = landStartTime[i] + landDuration[i];
                // if (waterStartTime[j] <= d) {
                //     d += waterDuration[j];
                // } else {
                //     d = waterStartTime[j] + waterDuration[j];
                // }
                d = max(d, waterStartTime[j]) + waterDuration[j];
                ans = min(ans, d);

                // Water->Land
                int d2 = waterStartTime[j] + waterDuration[j];
                // if (landStartTime[i] <= d2) {
                //     d2 += landDuration[i];
                // } else {
                //     d2 = landStartTime[i] + landDuration[i];
                // }
                d2 = max(d2, landStartTime[i]) + landDuration[i];
                ans = min(ans, d2);
            }
        }
        return ans;
    }
};