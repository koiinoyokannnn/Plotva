#include "Cell.hpp"

int Cell::movesFrom() {
    int movesF = 0;
    int n = N;
    int x = this->x;
    int y = this->y;
    for (auto m : MOVES) {
        if (x + m.first >= 0 && x + m.first < n && y + m.second >= 0 && y + m.second < n) {
            movesF++;
        }
    }
    return movesF;
}

// const std::vector<std::pair<int, int>> MOVES = {
//     {1, -2}, {2, -1}, {2, 1}, {1, 2},
//     {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}
// };
