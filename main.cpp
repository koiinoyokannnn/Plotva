#include <iostream>
#include <vector>
#include "Cell.hpp"
#include "Plotva.hpp"
#include <ctime>

unsigned int N;
std::vector<std::pair<int, int>> MOVES = {
    {1, -2}, {2, -1}, {2, 1}, {1, 2},
    {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}
};

int main() {
    std::cout << "Enter board size N: ";
    std::cin >> N;
    if (N < 5)
        return 1;
    int startX, startY;
    std::cout << "Enter starting position (x y, from 0 to " << (N-1) << "): ";
    std::cin >> startX >> startY;
    if (startX < 0 || startX >= N || startY < 0 || startY >= N) {
        std::cout << "Invalid starting position!" << std::endl;
        return 1;
    }
    std::vector<std::vector<Cell>> cells = newBoard(startX, startY);
    std::cout << "Initial board:" << std::endl;
    drawCells(cells);
    std::cout << std::endl;

    Plotva newPlotva(startX, startY);
    clock_t startTime = clock();
    for (int i = 0; i < (N*N-1); i++) {
        std::cout << "#" << (i+1) << ":\n";
        newPlotva.nextMove(cells);
    }
    clock_t endTime = clock();
    double milliseconds = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000;

    std::cout << "Program execution time: " << milliseconds << " мс" << std::endl;


    return 0;
}