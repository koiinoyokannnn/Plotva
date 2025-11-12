#include "Plotva.h"

void Plotva::nextMove(std::vector<std::vector<Cell>> &cells) {
    std::vector<std::pair<int, int>> possibleMoves;
    std::vector<int> moveScores;

    std::cout << nowI << " " << nowJ;

    // Проверяем все возможные ходы из текущей позиции
    for (auto &move : MOVES) {
        int newX = nowI + move.first;
        int newY = nowJ + move.second;

        // Проверяем, что ход допустим и клетка не посещена
        if (checkMove(nowI, nowJ, move) && !cells[newX][newY].passed) {
            possibleMoves.push_back({newX, newY});
            // Считаем количество возможных ходов из этой новой позиции
            int score = countMovesFrom(newX, newY, cells);
            moveScores.push_back(score);
        }
    }

    if (possibleMoves.empty()) {
        std::cout << "\nNo possible moves from (" << nowI << ", " << nowJ << ")!" << std::endl;
        return;
    }

    // Находим ход с минимальным score (правило Варнсдорфа)
    int bestIndex = 0;
    int minScore = moveScores[0];
    for (int i = 1; i < moveScores.size(); i++) {
        if (moveScores[i] < minScore) {
            minScore = moveScores[i];
            bestIndex = i;
        }
    }

    // Выполняем лучший ход
    auto bestMove = possibleMoves[bestIndex];
    nowI = bestMove.first;
    nowJ = bestMove.second;

    // Помечаем новую клетку как посещенную
    cells[nowI][nowJ].passed = true;

    std::cout << " " << nowI << " " << nowJ << "\n";
}