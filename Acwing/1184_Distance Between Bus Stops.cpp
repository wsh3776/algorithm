// 1184_Distance Between Bus Stops
class Solution {
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
        int n = distance.size();
        for (int i = 0; i < n; i ++) {
            distance.push_back(distance[i]);
        }

        if (start > destination) swap(start, destination);
        int d1 = 0, d2 = 0;
        for (int i = start; i <= destination; i ++)
        	d1 += distance[i];
        }

        for (int i = destination; i <= n + start; i ++) {
        	d2 += distance[i];
        }

        return min(d1, d2);
};