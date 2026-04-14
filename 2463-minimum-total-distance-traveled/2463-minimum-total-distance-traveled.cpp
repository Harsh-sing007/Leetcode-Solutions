class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> factoryPositions;
        for (auto& f : factory)
            for (int i = 0; i < f[1]; i++) factoryPositions.push_back(f[0]);
        return calculateMinDistance(0, 0, robot, factoryPositions);
    }

    long long calculateMinDistance(int robotIdx, int factoryIdx,
                                   vector<int>& robot,
                                   vector<int>& factoryPositions) {
        if (robotIdx == robot.size()) return 0;
        if (factoryIdx == factoryPositions.size()) return 1e12;
        long long assign = abs(robot[robotIdx] - factoryPositions[factoryIdx]) +
                           calculateMinDistance(robotIdx + 1, factoryIdx + 1,
                                                robot, factoryPositions);
        long long skip = calculateMinDistance(robotIdx, factoryIdx + 1, robot,
                                              factoryPositions);

        return min(assign, skip);
    }
};