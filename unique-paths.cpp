//
// Created by admin on 2018/10/23.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> map(m + 1, vector<int>(n + 1, 0));
        map[1][0] = 1;
        for (int i = 1; i < m + 1; ++i) {
            cout << endl;
            for (int j = 1; j < n + 1; ++j) {

                map[i][j] = map[i][j - 1] + map[i - 1][j];
                cout << map[i][j] << " ";
            }
        }
        return map[m][n];
    }
};

int main(){
    Solution s;
    std::cout << s.uniquePaths(4, 3) << std::endl;
    return 0;
}