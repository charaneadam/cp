#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <limits>

using namespace std;

class CreatureTraining {
private:
    vector<int> power;
    long long solve(){
        return 0;
    }
public:
    long long maximumPower(vector<int> count, vector<int> p, int D) {
        this->power = move(p);
        return 0;
    }
};

int main(){
    CreatureTraining solver;
    cout << solver.maximumPower({1, 2, 3, 4, 5}, {1, 4, 9, 16, 25}, 10);
    return 0;
}