class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stds;
        queue<int> sands;

        for (int i = 0; i < students.size(); i++) {
            stds.push(students[i]);
            sands.push(sandwiches[i]);
        }
        int n = stds.size();
        int ans = n;
        int i = 0;
        while (1) {
            bool found = 0;
            for (int i = 0; i < n; i++) {
                if (stds.front() == sands.front()) {
                    stds.pop();
                    sands.pop();
                    ans--;
                    found = 1;
                } else {
                    stds.push(stds.front());
                    stds.pop();
                }
                if (ans == 0) {
                    return 0;
                }
            }
            if (!found) {
                break;
            }
        }
        return ans;
    }
};