#include "Cell.hpp"


std::vector<std::vector<Cell>> newBoard() {
    std::vector<std::vector<Cell>> cells(N, std::vector<Cell>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cells[i][j].x = i;
            cells[i][j].y = j;
            cells[i][j].passed = false;
        }
    }
    cells[0][0].passed = true;
    return cells;
}

bool checkMove(int &X, int &Y, std::pair<int, int> move) {
        if (X + move.first >= 0 && X + move.first < N && Y + move.second >= 0 && Y + move.second < N)
            return true;
        return false;
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

void drawCells(std::vector<std::vector<Cell>> cells) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << cells[i][j].x << cells[i][j].y << "(" << countMovesFrom(i, j, cells) << ")" << " ";
        }
        std::cout << std::endl;
    }
}


// const std::vector<std::pair<int, int>> MOVES = {
//     {1, -2}, {2, -1}, {2, 1}, {1, 2},
//     {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}
// };
