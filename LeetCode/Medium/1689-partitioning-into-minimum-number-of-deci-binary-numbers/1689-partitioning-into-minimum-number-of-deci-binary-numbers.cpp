class Solution {
public:
    int minPartitions(string n) {
        // keep subtracting 1 from each dig till its become 0
        // continue rest of digits till all becomes 0
        // examples
        // 32
        // --
        // 11 [21]
        // 11 [10]
        // 10 [00]
        // --
        // 32

        // 82734
        // -----
        // 11111 [71623] ...
        // 11111
        // 10111
        // 10101
        // 10100
        // 10100
        // 10100
        // 10000

        // get max dig from n
        // that is ans
        int maxi = 0;
        for (auto i : n) {
            maxi = max(maxi, i - '0');
        }
        return maxi;
    }
};