#pragma once
#include <vector>

extern unsigned int N;
extern std::vector<std::pair<int, int>> MOVES;

struct Cell {
    bool passed = false;
};

std::vector<std::vector<Cell>> newBoard(int startX, int startY);
int countMovesFrom(int x, int y, const std::vector<std::vector<Cell>>& cells);
bool checkMove(int x, int y, std::pair<int, int> move);