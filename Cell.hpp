#pragma once
#include <vector>
const unsigned int N = 8;

const std::vector<std::pair<int, int>> MOVES = {
    {1, -2}, {2, -1}, {2, 1}, {1, 2},
    {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}
};

class Cell {
public:
    int x;
    int y;
    bool passed;
    int movesFrom();
};