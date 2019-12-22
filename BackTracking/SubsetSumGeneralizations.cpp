#include <bits/stdc++.h>
using namespace std;

int NumberOfSubsetsSummingUpToT(int t, int pos, vector<int> &list){
    if(t == 0) return 1;
    if(pos == list.size()) return 0;
    int a=0,b;
    if(list[pos] <= t){
        a = NumberOfSubsetsSummingUpToT(t-list[pos], pos+1, list);
    }
    b = NumberOfSubsetsSummingUpToT(t, pos+1, list);
    return a + b;
}

int MaxWeightofSubsetSummingToT(int t, int pos, vector<int> &list, vector<int> &weights){
    if(t == 0) return 0;
    if(pos == list.size()) return 0;
    int a=0, b;
    if(list[pos] <= t){
        a = weights[pos] + MaxWeightofSubsetSummingToT(t-list[pos], pos + 1, list, weights);
    }
    b = MaxWeightofSubsetSummingToT(t, pos+1, list, weights);
    return max(a, b);
}

int main(){
    vector<int> t = {2, 3, 5, 7};
    vector<int> w = {4,6,5,6};
    cout << MaxWeightofSubsetSummingToT(10, 0, t, w);
}