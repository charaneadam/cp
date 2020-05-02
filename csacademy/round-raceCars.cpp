#include <bits/stdc++.h>

using namespace std;

// https://csacademy.com/contest/round-75/task/race-cars/statement/

int main(){
    int n;
    double d,v,x,y;
    cin >> n >> x >> y;
    vector<pair<double, int>> distance_velocity(n), normal_time(n), reduced_time(n);
    for(int i=0; i<n; i++){
        cin >> d >> v;
        distance_velocity[i].first = d;
        distance_velocity[i].second = v;
        normal_time[i].first = d/v;
        normal_time[i].second = i;
        reduced_time[i].first = d/(v-y);
        reduced_time[i].second = i;
    }
    sort(normal_time.begin(), normal_time.end());
    sort(reduced_time.begin(), reduced_time.end());
    for(int i=0; i<n; i++){
        double ntime = distance_velocity[i].first/distance_velocity[i].second;
        double itime = distance_velocity[i].first/(distance_velocity[i].second+x);
        int itime_idx = lower_bound(normal_time.begin(), normal_time.end(), make_pair(itime, i)) - normal_time.begin();
        int ntime_idx = lower_bound(reduced_time.begin(), reduced_time.end(), make_pair(ntime, i)) - reduced_time.begin();
        cout << min(itime_idx, ntime_idx) + 1 << endl;
    }
}