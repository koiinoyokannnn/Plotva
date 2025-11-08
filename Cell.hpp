#pragma once
#include <vector>
#include "iostream"
const unsigned int N = 8;

const std::vector<std::pair<int, int>> MOVES = {
    {1, -2}, {2, -1}, {2, 1}, {1, 2},
    {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}
};

bool checkMove(int &X, int &Y, std::pair<int, int> move);

class Cell {
public:
    int x;
    int y;
    bool passed;
};

std::vector<std::vector<Cell>> newBoard();

void drawCells(std::vector<std::vector<Cell>> cells);

int countMovesFrom(int x, int y, const std::vector<std::vector<Cell>>& cells);