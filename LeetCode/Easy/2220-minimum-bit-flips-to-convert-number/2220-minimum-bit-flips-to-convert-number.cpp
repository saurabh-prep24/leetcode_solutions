class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flips = 0;
        while (start || goal) {
            if ((start & 1) != (goal & 1)) {
                flips++;
            }
            start >>= 1;
            goal >>= 1;
        }
        return flips;
    }
};