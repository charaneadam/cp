#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MaxHistogramArea{
public:
    int getMaxArea(vector<int> hist){
        stack<int> s;
        int n = (int)hist.size();
        int max_area = 0;
        int tp;
        int area_with_top;
        int i = 0;
        while (i < n){
            if (s.empty() || hist[s.top()] <= hist[i])
                s.push(i++);
            else{
                tp = s.top();
                s.pop();
                area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
                if (max_area < area_with_top)
                    max_area = area_with_top;
            }
        }
        while (!s.empty()){
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            if (max_area < area_with_top)
                max_area = area_with_top;
        }

        return max_area;
    }
};

class Solution {
public:
    int biggestTable(vector<vector<char>>& grid) {
        vector<int> temp(grid[0].size());
        MaxHistogramArea mh;
        int max_area = 0;
        int area = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<(int)temp.size(); j++){
                if(grid[i][j] == '0')
                    temp[j] = 0;
                else
                    temp[j] += (grid[i][j] - '0');
            }
            area = mh.getMaxArea(temp);
            max_area = max(area, max_area);
        }
        return max_area;
    }
};

int main(){
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
    cout << solution.biggestTable(vect);


    return 0;
}