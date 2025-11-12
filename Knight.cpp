#include "Knight.h"
#include <algorithm>

inline int distanceSqToCenter(int x, int y) {
    int center = N / 2;
    return (x - center) * (x - center) + (y - center) * (y - center);
}

bool Knight::warnsdorffOptimized(std::vector<std::vector<Cell>>& cells) {
    std::vector<std::vector<int>> distances(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            distances[i][j] = distanceSqToCenter(i, j);
        }
    }

    for (int moveCount = 1; moveCount < N * N; moveCount++) {
        int bestScore = 9;
        int bestX = -1, bestY = -1;
        int bestDistance = 0;

        for (auto &move : MOVES) {
            int newX = nowI + move.first;
            int newY = nowJ + move.second;

            if (newX >= 0 && newX < N && newY >= 0 && newY < N &&
                !cells[newX][newY].passed) {

                int score = 0;
                for (auto &m : MOVES) {
                    int nextX = newX + m.first;
                    int nextY = newY + m.second;
                    if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N &&
                        !cells[nextX][nextY].passed) {
                        score++;
                    }
                }

                if (score < bestScore ||
                   (score == bestScore && distances[newX][newY] > bestDistance)) {
                    bestScore = score;
                    bestX = newX;
                    bestY = newY;
                    bestDistance = distances[newX][newY];
                }
            }
        }

        if (bestX == -1) return false;

        nowI = bestX;
        nowJ = bestY;
        cells[nowI][nowJ].passed = true;
        path.push_back({nowI, nowJ});
    }
    return true;
}

bool Knight::findTour(std::vector<std::vector<Cell>>& cells) {
    return warnsdorffOptimized(cells);
}

void Knight::printPath() {
    std::ios_base::sync_with_stdio(false);
    for (size_t i = 0; i < path.size() - 1; i++) {
        std::cout << path[i].first << " " << path[i].second << " "
                  << path[i + 1].first << " " << path[i + 1].second;
        if (i != path.size() - 2) std::cout << "\n";
    }
    std::cout << std::endl;
}