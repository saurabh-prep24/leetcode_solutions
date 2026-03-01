class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flips = 0;
        // loop till any set bit remaining
        while (start || goal) {
            // check if both bits at end are equal
            // if not then increament flips
            if ((start & 1) != (goal & 1)) {
                flips++;
            }
            // right shift both
            start >>= 1;
            goal >>= 1;
        }
        // return ans
        return flips;
    }
};