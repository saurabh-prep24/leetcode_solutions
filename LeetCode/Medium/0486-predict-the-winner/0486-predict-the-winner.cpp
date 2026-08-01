class Solution {
public:
    // time: O(2^n)
    // space: O(n) - rec stack
    bool solveRec(vector<int>& nums, int start, int end, int score1, int score2,
                  int turn) {
        if (start > end) {
            if (score1 >= score2) {
                // cout << score1 << " " << score2 << endl;
                return true;
            }
            return false;
        }

        // player1
        if (turn == 1) {
            bool left =
                solveRec(nums, start + 1, end, score1 + nums[start], score2, 2);
            bool right =
                solveRec(nums, start, end - 1, score1 + nums[end], score2, 2);
            // player 1 should win by either of left or right choices
            if (left || right) {
                return true;
            }
        } else if (turn == 2) { // player2
            bool left =
                solveRec(nums, start + 1, end, score1, score2 + nums[start], 1);
            bool right =
                solveRec(nums, start, end - 1, score1, score2 + nums[end], 1);
            // player 2 should not allow player 1 to win in any left or right
            // choice then only player 2 wins
            if (left && right) {
                return true;
            }
        }
        return false;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return solveRec(nums, 0, n - 1, 0, 0, 1);
    }
};