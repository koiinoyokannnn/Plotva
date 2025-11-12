#include "Cell.h"

std::vector<std::vector<Cell>> newBoard(int startX, int startY) {
    std::vector<std::vector<Cell>> board(N, std::vector<Cell>(N));
    board[startX][startY].passed = true;
    return board;
}

bool checkMove(int x, int y, std::pair<int, int> move) {
    int newX = x + move.first;
    int newY = y + move.second;
    return (newX >= 0 && newX < N && newY >= 0 && newY < N);
}

int countMovesFrom(int x, int y, const std::vector<std::vector<Cell>>& cells) {
    int movesCount = 0;
    for (auto &move : MOVES) {
        int newX = x + move.first;
        int newY = y + move.second;
        if (checkMove(x, y, move) && !cells[newX][newY].passed) {
            movesCount++;
        }
    }
    return movesCount;
}