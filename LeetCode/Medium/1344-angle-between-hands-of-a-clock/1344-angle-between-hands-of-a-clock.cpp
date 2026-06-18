class Solution {
public:
    /*
    hour hand
    12 hrs = 360 deg
    1 h = 30 deg
    min hand
    1 min = 30/5 = 6 deg
    */
    double angleClock(int hour, int minutes) {
        double hrDeg = (hour % 12 + minutes / 60.0) * (360 / 12);
        double minDeg = minutes * (360 / 60);
        // cout << hrDeg << " : " << minDeg << endl;
        double ans = abs(hrDeg - minDeg);
        return min(ans, 360 - ans);
    }
};