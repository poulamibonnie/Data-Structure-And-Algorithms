class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasAvailable = 0;
        int gasRequired = 0;
        int n = gas.size();

        for (int i = 0; i < n; i++) {
            gasAvailable += gas[i];
            gasRequired += cost[i];
        }

        if (gasRequired > gasAvailable) {
            return -1;
        }

        int start = 0;
        int gasUsed = 0;
        for (int i = 0; i < n; i++) {
            gasUsed += (gas[i] - cost[i]);
            if (gasUsed < 0) {
                gasUsed = 0;
                start = i + 1;
            }
        }

        return start;

    }
};
