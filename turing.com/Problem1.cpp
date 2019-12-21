#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int rows;
    int cols;
    vector<vector<bool>> visited;
    vector<int> dirs_x = {1, 0, -1, 0};
    vector<int> dirs_y = {0, 1, 0, -1};
    bool good(int row, int col, vector<vector<char>>& grid){
        return (row >= 0 && row < this->rows && col >= 0 && col < this->cols && !this->visited[row][col] && grid[row][col] == '1');
    }
    void dfs(int row, int col, vector<vector<char>>& grid){
        this->visited[row][col] = true;
        for(int i=0; i<4; i++){
            int x,y;
            x = row + this->dirs_x[i];
            y = col + this->dirs_y[i];
            if(good(x, y, grid))
                dfs(x, y, grid);
        }
    }
public:
    int numOffices(vector<vector<char>>& grid) {
        // Put code here
        this->rows = (int)grid.size();
        this->cols = (this->rows > 0 ? (int)grid[0].size() : 0);
        this->visited.assign(this->rows, vector<bool>(this->cols, false));
        int offices = 0;
        for(int i=0; i<this->rows; i++){
            for(int j=0; j<this->cols; j++)
                if(good(i, j, grid)){
                    dfs(i, j, grid);
                    offices += 1;
                }
        }
        return offices;
    }
};

int main()
{
    // Parsing input here
    int rows, columns;

    cin >> rows;
    cin >> columns;

    vector<vector<char>> vect(rows);

    for (int i = 0; i < rows; i++) {
        vect[i] = vector<char>(columns);
        for (int j = 0; j < columns; j++) {
            cin >> vect[i][j];
        }
    }

    Solution solution;
    cout << solution.numOffices(vect);

    return 0;
}
