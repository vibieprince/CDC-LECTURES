#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<int>>& board, int row, int col) {
    // check column
    for (int i = row; i >= 0; i--)
        if (board[i][col] == 1) return false;

    // check left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;

    // check right diagonal
    for (int i = row, j = col; i >= 0 && j < 4; i--, j++)
        if (board[i][j] == 1) return false;

    return true;
}

bool placeQueens(vector<vector<int>>& board, int row) {
    if (row == 4) return true;
    for (int i = 0; i < 4; i++) {
        if (isValid(board, row, i)) {
            board[row][i] = 1;
            if (placeQueens(board, row + 1)) return true;
            board[row][i] = 0;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> board(4, vector<int>(4, 0));
    if (placeQueens(board, 0)) {
        cout << "Solution:\n";
        for (auto row : board) {
            for (auto val : row)
                cout << val << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists.\n";
    }
    return 0;
}
