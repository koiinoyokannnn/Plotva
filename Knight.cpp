#include "Knight.h"
#include <stdexcept>

bool Knight::nextMove(std::vector<std::vector<Cell>> &cells) {
    std::vector<std::pair<int, int>> possibleMoves;
    std::vector<int> moveScores;

    for (auto &move : MOVES) {
        int newX = nowI + move.first;
        int newY = nowJ + move.second;

        if (checkMove(nowI, nowJ, move) && !cells[newX][newY].passed) {
            possibleMoves.push_back({newX, newY});
            int score = countMovesFrom(newX, newY, cells);
            moveScores.push_back(score);
        }
    }

    if (possibleMoves.empty()) {
        return false;
    }

    int bestIndex = 0;
    int minScore = moveScores[0];
    for (int i = 1; i < moveScores.size(); i++) {
        if (moveScores[i] < minScore) {
            minScore = moveScores[i];
            bestIndex = i;
        }
    }

    auto bestMove = possibleMoves[bestIndex];
    nowI = bestMove.first;
    nowJ = bestMove.second;
    cells[nowI][nowJ].passed = true;
    path.push_back({nowI, nowJ});

    return true;
}

void Knight::printPath() {
    for (size_t i = 0; i < path.size() - 1; i++) {
        std::cout << path[i].first << " " << path[i].second << " "
                  << path[i + 1].first << " " << path[i + 1].second;
        if (i != path.size() - 2) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}