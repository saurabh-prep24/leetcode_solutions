class Solution {
public:
    // time: O(n logn)
    // time: O(1)
    bool sortingSolve(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int i = 0;
        long long currMass = mass;
        while (i < asteroids.size()) {
            if (currMass < asteroids[i]) {
                // not possible to destroy
                return 0;
            } else {
                // merged to mass
                currMass += asteroids[i];
            }
            i++;
        }
        return 1;
    }
    // time: O(n logn)
    // time: O(n)
    bool heapSolve(int mass, vector<int>& asteroids) {
        int i = 0;
        long long currMass = mass;
        priority_queue<int, vector<int>, greater<int>> pq;
        while (i < asteroids.size()) {
            if (currMass < asteroids[i]) {
                // not possible to destroy
                pq.push(asteroids[i]);
            } else {
                // merged to mass
                currMass += asteroids[i];
            }
            i++;
        }
        if (pq.size() == asteroids.size()) {
            return 0;
        }
        while (!pq.empty()) {
            cout << pq.top() << endl;
            if (pq.top() > currMass) {
                return 0;
            }
            currMass += pq.top();
            pq.pop();
        }
        return pq.empty();
    }
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // return sortingSolve(mass, asteroids);
        return heapSolve(mass, asteroids);
    }
};