#pragma once
#include <vector>
#include <iostream>
extern unsigned int N;  // Теперь extern, определяется в main

extern std::vector<std::pair<int, int>> MOVES;  // Теперь extern

bool checkMove(int &X, int &Y, std::pair<int, int> move);

class Cell {
public:
    int x;
    int y;
    bool passed;
};

std::vector<std::vector<Cell>> newBoard(int startX, int startY);

void drawCells(std::vector<std::vector<Cell>> cells);

int countMovesFrom(int x, int y, const std::vector<std::vector<Cell>>& cells);