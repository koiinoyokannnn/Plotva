#include <iostream>
#include <vector>
#include "Cell.h"
#include "Knight.h"
#include <ctime>
#include <iomanip>

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
    Knight newPlotva(startX, startY);

    clock_t startTime = clock();
    bool success = true;
    for (int i = 0; i < (N*N-1); i++) {
        if (!newPlotva.nextMove(cells)) {
            success = false;
            break;
        }
    }
    clock_t endTime = clock();
    double milliseconds = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000;

    // Выводим время ДО ходов
    std::cout << std::fixed << std::setprecision(6) << milliseconds << std::endl;

    // Затем выводим маршрут
    if (success) {
        newPlotva.printPath();
    }

    return 0;
}
