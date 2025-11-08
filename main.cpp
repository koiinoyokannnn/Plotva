#include <iostream>
#include <vector>
#include "Cell.hpp"

std::vector<std::vector<Cell>> newBoard() {
    std::vector<std::vector<Cell>> cells(N, std::vector<Cell>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cells[i][j].x = i;
            cells[i][j].y = j;
            cells[i][j].movesFrom();
            cells[i][j].passed = false;
        }
    }
    return cells;
}

void drawCells(std::vector<std::vector<Cell>> cells) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << cells[i][j].x << cells[i][j].y << "(" << cells[i][j].movesFrom() << ")" << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<Cell>> cells = newBoard();
    drawCells(cells);

    return 0;
}