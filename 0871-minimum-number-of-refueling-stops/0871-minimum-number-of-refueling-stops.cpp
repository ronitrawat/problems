class Solution {
public:
    int minRefuelStops(int target,
                       int startFuel,
                       vector<vector<int>>& stations) {

        priority_queue<int> pq;

        long long reach = startFuel;

        int i = 0;
        int n = stations.size();

        int stops = 0;

        while(reach < target) {

            // Add all reachable stations
            while(i < n &&
                  stations[i][0] <= reach) {

                pq.push(stations[i][1]);
                i++;
            }

            // No fuel available
            if(pq.empty())
                return -1;

            reach += pq.top();
            pq.pop();

            stops++;
        }

        return stops;
    }
};