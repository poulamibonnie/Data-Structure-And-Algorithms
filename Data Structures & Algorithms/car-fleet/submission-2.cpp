class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> serializer;
        int fleetCounter = 1;

        for (int i = 0; i < position.size(); i++) {
            serializer.push_back({position[i], speed[i]});
        }
        sort(serializer.rbegin(), serializer.rend());

        double prevTime = (double)(target - serializer[0].first)/ serializer[0].second;
        for (int i = 1; i < position.size(); i++) {
            double currTime = (double)(target - serializer[i].first)/ serializer[i].second;
            if (prevTime < currTime) {
                fleetCounter++;
                prevTime = currTime;
            }
            
        }
        


        return fleetCounter;
    }
};
