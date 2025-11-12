#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include "Cell.h"
#include "Knight.h"

unsigned int N;
std::vector<std::pair<int, int>> MOVES = {
    {1, -2}, {2, -1}, {2, 1}, {1, 2},
    {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}
};

int main() {
    int startX, startY;
    std::cin >> N >> startX >> startY;
    if (N < 5)
        return 1;
    if (startX < 0 || startX >= N || startY < 0 || startY >= N) {
        return 1;
    }

    std::vector<std::vector<Cell>> cells = newBoard(startX, startY);
    Knight knight(startX, startY);

    clock_t startTime = clock();
    bool success = knight.findTour(cells);
    clock_t endTime = clock();
    double milliseconds = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000;

    std::cout << std::fixed << std::setprecision(6) << milliseconds << std::endl;

    if (success) {
        knight.printPath();
    } else {
        return 1;
    }

    return 0;
}