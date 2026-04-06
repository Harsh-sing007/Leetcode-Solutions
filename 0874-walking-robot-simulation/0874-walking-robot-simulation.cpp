class Solution {
private:
    static const long long HASH_MULTIPLIER =
        60013;  
    long long hashCoordinates(long long x, long long y) {
        return x + HASH_MULTIPLIER * y;
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obstacleSet;
        for (auto& obstacle : obstacles) {
            obstacleSet.insert(hashCoordinates(obstacle[0], obstacle[1]));
        }
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<int> currentPosition = {0, 0};
        int maxDistanceSquared = 0;
        int currentDirection = 0; 

        for (int command : commands) {
            if (command == -1) {
                currentDirection = (currentDirection + 1) % 4;
                continue;
            }
            if (command == -2) {
                currentDirection = (currentDirection + 3) % 4;
                continue;
            }
            vector<int> direction = directions[currentDirection];
            for (int step = 0; step < command; step++) {
                int nextX = currentPosition[0] + direction[0];
                int nextY = currentPosition[1] + direction[1];
                if (obstacleSet.contains(hashCoordinates(nextX, nextY))) {
                    break;
                }
                currentPosition[0] = nextX;
                currentPosition[1] = nextY;
            }

            maxDistanceSquared =
                max(maxDistanceSquared,
                    currentPosition[0] * currentPosition[0] +
                        currentPosition[1] * currentPosition[1]);
        }

        return maxDistanceSquared;
    }
};