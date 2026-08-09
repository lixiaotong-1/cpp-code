// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围。
#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<char>>& grid, int i, int j) {
    int row = grid.size();
    int col = grid[0].size();
    if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int numIslands(std::vector<std::vector<char>>& grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }
    int count = 0;
    int row = grid.size();
    int col = grid[0].size();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (grid[i][j] == '1') {
                ++count;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

int main() {
    int row = 0, col = 0;
    std::cin >> row;
    std::cin >> col;
    std::vector<std::vector<char>> grid(row, std::vector<char>(col, '0'));
    for (int i = 0; i < row; ++i) {
        int ch = 0;
        for (int j = 0; j <col; ++j) {
            std::cin >> ch;
            grid[i][j] = ch + '0';
        }
    }
    int res = numIslands(grid);
    std::cout << res << "\n";
}