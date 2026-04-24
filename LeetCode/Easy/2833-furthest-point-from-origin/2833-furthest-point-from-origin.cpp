class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0, countR = 0, na = 0;
        for (auto i : moves) {
            if (i == 'L')
                countL++;
            else if (i == 'R')
                countR++;
            else
                na++;
        }
        int totalL = countL, totalR = countR;
        if (countL >= countR) {
            totalL += na;
        } else {
            totalR += na;
        }

        return abs(totalR - totalL);
    }
};