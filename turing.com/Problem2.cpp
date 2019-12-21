#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
private:
    map<char, vector<int>> s1;
public:
    int minimumConcat(string initial, string goal) {
        for(int i=0; i<(int)initial.size(); i++){
            s1[initial[i]].emplace_back(i);
        }
        int ans = 1;
        int last = -1;
        for(auto c : goal){
            if(s1.count(c)){
                int fst = -1;
                for(auto idx : s1[c]){
                    if(idx > last){
                        fst = idx;
                        break;
                    }
                }
                if(fst == -1){
                    last = s1[c][0];
                    ans++;
                }else last = fst;
            }
            else{
                ans = -1;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    // Parsing input here
    string initial, goal;

    cin >> initial;
    cin >> goal;

    Solution solution;
    cout << solution.minimumConcat(initial, goal);

    return 0;
}