#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> scientists(n);
    map<int, int> cnt;
    for(auto &s : scientists){
        cin >> s;
        if(cnt.find(s) != cnt.end()) cnt[s] += 1;
        else cnt[s] = 1;
    }
    int m;
    cin >> m;
    vector<int> audios(m), subtitles(m);
    for(auto &a : audios) cin >> a;
    for(auto &sub : subtitles) cin >> sub;
    vector<pair<int, int>> movies(m, pair<int, int>({0,0}));
    for(int i=0; i<m; i++){
        int audio = audios[i];
        int subtitle = subtitles[i];
        auto &movie = movies[i];
        if(cnt.find(audio) != cnt.end()) movie.first = cnt[audio];
        if(cnt.find(subtitle) != cnt.end()) movie.second = cnt[subtitle];
    }
    int best_ans = 0;
    for(int i=1; i<m; i++){
        if(
                (movies[i].first > movies[best_ans].first) ||
                (movies[i].first == movies[best_ans].first && movies[i].second > movies[best_ans].second)
           ) best_ans = i;
    }
    cout << best_ans + 1;
}