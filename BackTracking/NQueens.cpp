#include <bits/stdc++.h>
using namespace std;

class Board{
private:
    int n;
    vector<int> prev;
    int ans = 0;
    bool check(int i, int j){
        int x,y,diff;
        bool good = true;
        for(int k=0; k<i && good; k++){
            x = k;
            y = prev[k];
            diff = i-x;
            if(y == j || (x+diff == i && y+diff == j) || (x+diff == i && y-diff == j)){
                good = false;
            }
        }
        return good;
    }
    void showBoard(){
        ans ++;
        cout << "Current Board: ";
        for(auto c : prev){
            cout << c << ' ';
        }
        cout << endl;
    }
public:
    Board(int n){
        this->n = n;
    }
    void solve(int pos = 0){
        if(pos == this->n){
            // Solution found !
            this->showBoard();
        }
        for(int i=0; i<this->n; i++){
            if(this->check(pos, i)){
                this->prev.push_back(i);
                solve(pos+1);
                this->prev.pop_back();
            }
        }
    }
    int getNumberSolutions(){
        return this->ans;
    }
};

int main(){
    Board b = *new Board(8);
    b.solve();
    cout << "Number of solutions: " << b.getNumberSolutions();
}