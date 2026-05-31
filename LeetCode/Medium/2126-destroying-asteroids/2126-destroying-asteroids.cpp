class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
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
};