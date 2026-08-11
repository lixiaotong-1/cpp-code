// 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> res;

void backtrace(std::vector<std::string>& board, int row, int n, int& count, std::vector<bool>& visited_col,
               std::vector<bool>& visited_diag_right, std::vector<bool>& visited_diag_left) {
    if (count == n) {
        res.push_back(board);
        return;
    }
    
    for (int col = 0; col < n; ++col) {
        if (visited_col[col] || visited_diag_right[col - row + n] || visited_diag_left[col + row]) {
            continue;
        }
        board[row][col] = 'Q';
        visited_col[col] = true;
        visited_diag_right[col - row + n] = true;
        visited_diag_left[col + row] = true;
        ++count;
        backtrace(board, row + 1, n, count, visited_col, visited_diag_right, visited_diag_left);
        --count;
        visited_diag_left[col + row] = false;
        visited_diag_right[col - row + n] = false;
        visited_col[col] = false;
        board[row][col] = '.';
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::string> board(n, std::string(n, '.'));
    std::vector<bool> visited_col(n, false);
    std::vector<bool> visited_diag_right(2 * n, false);
    std::vector<bool> visited_diag_left(2 * n, false);
    int count = 0;
    backtrace(board, 0, n, count, visited_col, visited_diag_right, visited_diag_left);
    return res;
}

int main() {
    auto res = solveNQueens(4);
    for (const auto& vec: res) {
        for (const auto& str: vec) {
            std::cout << str << " ";
        }
        std::cout << "\n";
    }
}