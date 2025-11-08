#pragma once
#include "Cell.hpp"
#include <algorithm>
#include <iostream>

class Plotva {
private:
    int nowI = 0;
    int nowJ = 0;
public:
    void nextMove(std::vector<std::vector<Cell>> &cells);
    std::pair<int, int> getPosition() const { return {nowI, nowJ}; }
};