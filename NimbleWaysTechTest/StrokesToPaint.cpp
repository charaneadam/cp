#include <bits/stdc++.h>

using namespace std;

int h, w, dir_x[] = {1, 0, -1, 0}, dir_y[] = {0, 1, 0, -1};
vector<vector<bool>> vis;

bool good(int i, int j) {
    return (i >= 0 && i < h && j >= 0 && j < w && !vis[i][j]);
}

void dfs(int i, int j, vector<string> &picture) {
    vis[i][j] = true;
    int ii, jj;
    for (int k = 0; k < 4; k++) {
        ii = i + dir_y[k];
        jj = j + dir_x[k];
        if (good(ii, jj) && picture[i][j] == picture[ii][jj]) {
            dfs(ii, jj, picture);
        }
    }
}

int strokesRequired(vector<string> picture) {
    h = picture.size();
    w = picture[0].size();
    vis.assign(h + 1, vector<bool>(w + 1, false));
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!vis[i][j]) {
                ans += 1;
                dfs(i, j, picture);
            }
        }
    }
    return ans;
}

int main() {
    vector<string> picture = {"aabba", "aabba", "aaacb"};
    cout << strokesRequired(picture);
    return 0;
}