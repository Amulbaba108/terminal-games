#pragma once
#include <array>

using Board = std::array<char, 9>;  // squares 0-8, each 'X', 'O' or ' '

char winner(const Board& board); 
bool isFull(const Board& board);
int state(const Board& board); // calculating the state of the board (3^9 possible states)
int max(int a, int b);
int chooseMove(Board board, char me, char opponent); // minimax algorithm applies here
void resetMemo(); // clears the minimax dp table, call before any new game/search
int computerMove(const Board& board, char me, char opponent);  
void playTicTacToe();
