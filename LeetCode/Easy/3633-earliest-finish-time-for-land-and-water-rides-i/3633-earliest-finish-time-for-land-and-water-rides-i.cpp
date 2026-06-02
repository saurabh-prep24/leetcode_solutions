class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ans = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {
                int d = landStartTime[i] + landDuration[i];
                if (waterStartTime[j] <= d) {
                    d += waterDuration[j];
                } else {
                    d = waterStartTime[j] + waterDuration[j];
                }
                // cout<<landStartTime[i] <<" - "<<landDuration[i]<<endl;
                // cout<<waterStartTime[j] <<" - "<<waterDuration[j]<<endl;
                // cout<<"d2 "<<d<<endl;

                ans = min(ans, d);
            }
        }

        for (int i = 0; i < waterStartTime.size(); i++) {
            for (int j = 0; j < landStartTime.size(); j++) {
                int d = waterStartTime[i] + waterDuration[i];
                if (landStartTime[j] <= d) {
                    d += landDuration[j];
                } else {
                    d = landStartTime[j] + landDuration[j];
                }
                // cout<<waterStartTime[i] <<" - "<<waterDuration[i]<<endl;
                // cout<<landStartTime[j] <<" - "<<landDuration[j]<<endl;
                // cout<<"d2 "<<d<<endl;

                ans = min(ans, d);
            }
        }
        return ans;
    }
};