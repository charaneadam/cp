#include <bits/stdc++.h>
using namespace std;

class OptimalStoring{
private:
    int n;
    vector<int> fileLengths;
    vector<int> frequencies;
public:
    explicit OptimalStoring(vector<int> &lengths){
        this->fileLengths = lengths;
        this->n = (int)this->fileLengths.size();
        this->frequencies.assign(n, 1);
    }

    OptimalStoring(vector<int> &lengths, vector<int> &freqs) : OptimalStoring(lengths){
        this->frequencies = freqs;
    }

    vector<int> newIndicesOrder(){
        vector<pair<double, int>> ans(this->n);
        for(int i=0; i<this->n; i++){
            ans[i] = {(1.0 * fileLengths[i] / frequencies[i]), i};
        }
        sort(ans.begin(), ans.end());
        vector<int> res(this->n);
        for(int i=0; i<this->n; i++){
            res[i] = ans[i].second + 1;
        }
        return res;
    }
};

int main(){
    vector<int> lengths = { 5, 3, 10 };
    OptimalStoring opt = *new OptimalStoring(lengths);
    auto ans = opt.newIndicesOrder();
    for(auto a : ans) cout << a << ' ';
}