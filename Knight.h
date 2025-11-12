#pragma once
#include "Cell.h"
#include "iostream"
#include <vector>

class Knight {
private:
    int nowI, nowJ;
    std::vector<std::pair<int, int>> path;

    bool warnsdorffOptimized(std::vector<std::vector<Cell>>& cells);

public:
    Knight(int startX, int startY) : nowI(startX), nowJ(startY) {
        path.push_back({startX, startY});
    }
    bool findTour(std::vector<std::vector<Cell>>& cells);
    void printPath();
};