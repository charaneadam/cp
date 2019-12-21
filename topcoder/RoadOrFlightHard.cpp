#include <bits/stdc++.h>

using namespace std;

class RoadOrFlightHard{
private:
    vector<long long> road_time, flight_time;
public:
    long long minTime(int N, int roadFirst, int roadProd, int roadAdd, int roadMod, int flightFirst, int flightProd, int flightAdd, int flightMod, int K){
        this->road_time.assign(N, 0);
        this->flight_time.assign(N, 0);
        this->road_time[0] = roadFirst % roadMod;
        this->flight_time[0] = flightFirst % flightMod;
        for(int i=1; i<N-1; i++){
            this->road_time[i] = (this->road_time[i-1] * roadProd + roadAdd) % roadMod;
            this->flight_time[i] = (this->flight_time[i-1] * flightProd + flightAdd) % flightMod;
        }
        return 0LL;
    }
};