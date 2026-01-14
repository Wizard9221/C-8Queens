#include <iostream>
#include <cstdlib>

bool is_good(int board[], int col);
void backtrack(int board[], int* col);
void draw_board(int board[], int* col);

int main()
{
    int col = 0;
    int board[8] = {};
    bool emergency_break = true;

    while (col > -1)
    {
        while (!is_good(board, col))
        {
            if (++board[col] > 7) backtrack(board, &col);
        }

        if (col == -1) break;

        col++;
        if (col > 7) draw_board(board, &col);
    }
    return 0;
}

bool is_good(int board[], int col)
{
    int checker = board[col];
    if (checker > 7) return false;

    for (int a = 0; a < col; a++)
    {
        if (board[a] == checker) return false;
        if (col - a == abs(board[a] - checker)) return false;
    }
    return true;
}

void backtrack(int board[], int* col)
{
    board[(*col)--] = 0;
    board[*col]++;
}

void draw_board(int board[], int* col)
{
    static int tally = 1;
    std::cout << "Output #" << tally << ":" << std::endl;
    tally++;

    for (int a = 0; a < 8; a++)
    {
        for (int b = 0; b < 8; b++)
        {
            if (board[b] == a) std::cout << "1  ";
            else std::cout << "0  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    backtrack(board, col);
}