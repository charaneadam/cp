#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sols;

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
    void insertBoard(){
        this->ans++;
        vector<int> sol(8);
        for(int i=0; i<8; i++){
            sol[prev[i]] = i;
        }
        sols.push_back(sol);
    }
public:
    explicit Board(int n){
        this->n = n;
    }
    void generateBoards(int pos = 0){
        if(pos == this->n){
            // Solution found !
            this->insertBoard();
        }
        for(int i=0; i<this->n; i++){
            if(this->check(pos, i)){
                this->prev.push_back(i);
                generateBoards(pos+1);
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
    b.generateBoards();
    int board[8],a;
    int tc = 1;
    while(cin >> a){
        board[0] = a-1;
        for(int i=1; i<8; i++){
            cin >> a;
            board[i] = a-1;
        }
        int ans = 100000;
        vector<int> best_solution;
        for(auto sol : sols){
            int curr = 0;
            for(int i=0; i<8; i++){
                curr += sol[i] != board[i];
            }
            if(curr < ans){
                ans = curr;
                best_solution = sol;
            }
        }
        cout << "Case " << tc++ << ": " << ans << endl;
    }
}