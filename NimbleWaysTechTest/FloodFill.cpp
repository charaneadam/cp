#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void dfs(vector<vector<int>> &img, int x, int y, int c, int extreme){
    img[x][y] = extreme;
    int xx,yy,n,m;
    n = img.size();
    m = img[0].size();
    for(int i=0; i<4; i++){
        xx = x + dy[i];
        yy = y + dx[i];
        if(xx >= 0 && yy >= 0 && xx < n && yy < m && img[xx][yy] == c){
            dfs(img, xx, yy, c, extreme);
        }
    }
}

void solution(vector<vector<int>> &img, int new_color, int i, int j){
    int c = img[i][j];
    int extreme = 300;
    dfs(img, i, j, c, extreme);
    for(auto &row : img)
        for(auto &cell : row)
            if(cell == extreme)
                cell = new_color;
}

void show_img(const vector<vector<int>> &img){
    for(const auto &line : img){
        for(const auto &c : line) cout << c << ' ';
        cout << endl;
    }
}

int main(){
    vector<vector<int>> img =  {{1,2,3,4,1,5},{1,3,4,5,7,9},{0,1,5,5,8,9},{3,4,123,7,8,9},{7,1,5,0,3,1}};
    show_img(img);
    solution(img, 0, 1, 3);
    cout << endl;
    show_img(img);
    return 0;
}
