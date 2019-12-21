#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <sstream>
#include <limits>

using namespace std;

vector<int> p1,p2;
vector<string> p_1, p_2;

void solve(){
    for(auto c : p1) cout << c << ' ';
    cout << endl;
    for(auto c : p2) cout << c << ' ';
    cout << endl;
}



// Fuck it, the difficulty is in reading input not solving the problem ...

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    string line;
    unordered_map<string, int> w1;
    bool second = false;
    int cnt = 0;
    while(getline(cin, line)){
        if(line[0] == '#'){
            if(second){
                second = false;
                w1.clear();
                cnt = 0;
            }
            else{
                second = true;
            }
        }
        else{
            string tmp = "";
            if(second){
                for(auto w : line){
                    if(w != ' ' && w != '\n') tmp += w;
                    else{
                        if(!w1.count(tmp)) w1[tmp] = cnt++;
                        p2.push_back(w1[tmp]);
                        tmp = "";
                    }
                }
            }else{
                for(auto w : line){
                    if(w != ' ' && w != '\n') tmp += w;
                    else{
                        if(!w1.count(tmp)) w1[tmp] = cnt++;
                        p1.push_back(w1[tmp]);
                        tmp = "";
                    }

                }
            }
        }
    }
    solve();
    return 0;
}