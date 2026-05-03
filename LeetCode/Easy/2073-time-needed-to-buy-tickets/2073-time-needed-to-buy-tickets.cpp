class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        queue<int> q;
        // fill all index into q
        for (auto i = 0; i < tickets.size(); i++) {
            q.push(i);
        }

        // check till q non-emtpy and ticket[k] != 0
        while (!q.empty() && tickets[k] != 0) {
            // take out front index
            int front = q.front();
            q.pop();
            // check if its valid
            if (tickets[front] > 0) {
                // buy ticket so reduce and increment ans
                tickets[front]--;
                ans++;
                // check if need to enque again
                if (tickets[front] > 0) {
                    q.push(front);
                }
            }
        }
        return ans;
    }
};