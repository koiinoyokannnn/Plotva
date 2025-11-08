#include <iostream>
#include <vector>
#include "Cell.hpp"
#include "Plotva.hpp"

int main() {
    std::vector<std::vector<Cell>> cells = newBoard();
    std::cout << "Initial board:" << std::endl;
    drawCells(cells);
    std::cout << std::endl;

    Plotva newPlotva;
    for (int i = 0; i < (N*N-1); i++) {
        std::cout << "#" << (i+1) << ":\n";
        newPlotva.nextMove(cells);
    }

    return 0;
}