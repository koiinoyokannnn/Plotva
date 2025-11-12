#pragma once
#include "Cell.h"
#include <algorithm>
#include <iostream>

class Knight {
private:
    int nowI;
    int nowJ;
    std::vector<std::pair<int, int>> path;
public:
    Knight(int startX, int startY) : nowI(startX), nowJ(startY) {
        path.push_back({startX, startY});
    }
    bool nextMove(std::vector<std::vector<Cell>> &cells);
    std::pair<int, int> getPosition() const { return {nowI, nowJ}; }
    void printPath();
};