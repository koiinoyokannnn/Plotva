#pragma once
#include "Cell.hpp"
#include <algorithm>
#include <iostream>

class Plotva {
private:
    int nowI;
    int nowJ;
public:
    Plotva(int startX, int startY) : nowI(startX), nowJ(startY) {}  // Конструктор с начальной позицией
    void nextMove(std::vector<std::vector<Cell>> &cells);
    std::pair<int, int> getPosition() const { return {nowI, nowJ}; }
};