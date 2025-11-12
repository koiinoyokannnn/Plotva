#pragma once
#include <vector>
#include <iostream>
extern unsigned int N;
extern std::vector<std::pair<int, int>> MOVES;

bool checkMove(int &X, int &Y, std::pair<int, int> move);

class Cell {
public:
    int x;
    int y;
    bool passed;
};

std::vector<std::vector<Cell>> newBoard(int startX, int startY);
int countMovesFrom(int x, int y, const std::vector<std::vector<Cell>>& cells);
