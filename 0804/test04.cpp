// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围。
#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<char>>& board, int i, int j) {
    int row = board.size();
    int col = board[0].size();
    if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] != 'O') {
        return;
    }
    board[i][j] = '#';
    dfs(board, i - 1, j);
    dfs(board, i + 1, j);
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
}

void solve(std::vector<std::vector<char>>& board) {
    if (board.size() == 0 || board[0].size() == 0) {
        return;
    }
    int row = board.size();
    int col = board[0].size();
    
    for (int i = 0; i < row; ++i) {
        if (board[i][0] == 'O') {
            dfs(board, i, 0);
        }
        if (board[i][col - 1] == 'O') {
            dfs(board, i, col - 1);
        }
    }

    for (int j = 0; j < col; ++j) {
        if (board[0][j] == 'O') {
            dfs(board, 0, j);
        }
        if (board[row - 1][j] == 'O') {
            dfs(board, row - 1, j);
        }
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == '#') {
                board[i][j] = 'O';
            }
        }
    }
}

int main() {
    int row = 0, col = 0;
    std::cin >> row;
    std::cin >> col;
    std::vector<std::vector<char>> grid(row, std::vector<char>(col, 'X'));
    for (int i = 0; i < row; ++i) {
        char ch = 0;
        for (int j = 0; j <col; ++j) {
            std::cin >> ch;
            grid[i][j] = ch;
        }
    }
    solve(grid);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}