class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> serializer;
        stack<double> fleetCounter;

        for (int i = 0; i < position.size(); i++) {
            serializer.push_back({position[i], speed[i]});
        }
        sort(serializer.begin(), serializer.end(), greater<pair<int, int>>());

        double timeTaken = (double)(target - serializer[0].first)/ serializer[0].second;
        fleetCounter.push(timeTaken);

        for (int i = 1; i < position.size(); i++) {
            double prevTime = fleetCounter.top();
            double timeTaken = (double)(target - serializer[i].first)/ serializer[i].second;
            fleetCounter.push(timeTaken);
            if (!fleetCounter.empty() && prevTime >= timeTaken) {
                fleetCounter.pop();
            }
            
            
            cout<<timeTaken<<endl;
            
        }
        


        return fleetCounter.size();
    }
};
