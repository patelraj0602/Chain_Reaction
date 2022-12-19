#include <bits/stdc++.h>
using namespace std;

struct cell
{
    int row;
    int column;
    int critical_mass;
    int player = 0;
    int orbs = 0;
};
cell board[9][6];

void f(cell &p)
{
    int i = p.row;
    int j = p.column;
    int turn = p.player;
    board[i][j].player = 0;
    board[i][j].orbs = 0;
    if (i == 0 && j == 0)
    {
        board[i + 1][j].orbs++;
        board[i + 1][j].player = turn;
        if (board[i + 1][j].orbs == board[i + 1][j].critical_mass)
            f(board[i + 1][j]);
        board[i][j + 1].orbs++;
        board[i][j + 1].player = turn;
        if (board[i][j + 1].orbs == board[i][j + 1].critical_mass)
            f(board[i][j + 1]);
    }
    else if (j == 5 && i > 0 && i < 8)
    {
        board[i - 1][j].orbs++;
        board[i - 1][j].player = turn;
        if (board[i - 1][j].orbs == board[i - 1][j].critical_mass)
            f(board[i - 1][j]);
        board[i][j - 1].orbs++;
        board[i][j - 1].player = turn;
        if (board[i][j - 1].orbs == board[i][j - 1].critical_mass)
            f(board[i][j - 1]);
        board[i + 1][j].orbs++;
        board[i + 1][j].player = turn;
        if (board[i + 1][j].orbs == board[i + 1][j].critical_mass)
            f(board[i + 1][j]);
    }
    else if (i == 8 && j == 0)
    {
        board[i - 1][j].orbs++;
        board[i - 1][j].player = turn;
        if (board[i - 1][j].orbs == board[i - 1][j].critical_mass)
            f(board[i - 1][j]);
        board[i][j + 1].orbs++;
        board[i][j + 1].player = turn;
        if (board[i][j + 1].orbs >= board[i][j + 1].critical_mass)
            f(board[i][j + 1]);
    }
    else if (i == 0 && j == 5)
    {
        board[i][j - 1].orbs++;
        board[i][j - 1].player = turn;
        if (board[i][j - 1].orbs == board[i][j - 1].critical_mass)
            f(board[i][j - 1]);
        board[i + 1][j].orbs++;
        board[i + 1][j].player = turn;
        if (board[i + 1][j].orbs == board[i + 1][j].critical_mass)
            f(board[i + 1][j]);
    }
    else if (i == 8 && j == 5)
    {
        board[i - 1][j].orbs++;
        board[i - 1][j].player = turn;
        if (board[i - 1][j].orbs == board[i - 1][j].critical_mass)
            f(board[i - 1][j]);
        board[i][j - 1].orbs++;
        board[i][j - 1].player = turn;
        if (board[i][j - 1].orbs >= board[i][j - 1].critical_mass)
            f(board[i][j - 1]);
    }
    else if (i == 0 && (j > 0 && j < 5))
    {
        board[i][j - 1].orbs++;
        board[i][j - 1].player = turn;
        if (board[i][j - 1].orbs == board[i][j - 1].critical_mass)
            f(board[i][j - 1]);
        board[i][j + 1].orbs++;
        board[i][j + 1].player = turn;
        if (board[i][j + 1].orbs == board[i][j + 1].critical_mass)
            f(board[i][j + 1]);
        board[i + 1][j].orbs++;
        board[i + 1][j].player = turn;
        if (board[i + 1][j].orbs == board[i + 1][j].critical_mass)
            f(board[i + 1][j]);
    }
    else if (i == 8 && (j > 0 && j < 5))
    {
        board[i][j - 1].orbs++;
        board[i][j - 1].player = turn;
        if (board[i][j - 1].orbs == board[i][j - 1].critical_mass)
            f(board[i][j - 1]);
        board[i][j + 1].orbs++;
        board[i][j + 1].player = turn;
        if (board[i][j + 1].orbs >= board[i][j + 1].critical_mass)
            f(board[i][j + 1]);
        board[i - 1][j].orbs++;
        board[i - 1][j].player = turn;
        if (board[i - 1][j].orbs == board[i - 1][j].critical_mass)
            f(board[i - 1][j]);
    }
    else if (j == 0 && (i > 0 && i < 8))
    {
        board[i - 1][j].orbs++;
        board[i - 1][j].player = turn;
        if (board[i - 1][j].orbs == board[i - 1][j].critical_mass)
            f(board[i - 1][j]);
        board[i][j + 1].orbs++;
        board[i][j + 1].player = turn;
        if (board[i][j + 1].orbs == board[i][j + 1].critical_mass)
            f(board[i][j + 1]);
        board[i + 1][j].orbs++;
        board[i + 1][j].player = turn;
        if (board[i + 1][j].orbs == board[i + 1][j].critical_mass)
            f(board[i + 1][j]);
    }

    else if ((j > 0 && j < 5) && (i > 0 && i < 8))
    {
        board[i - 1][j].orbs++;
        board[i - 1][j].player = turn;
        if (board[i - 1][j].orbs == board[i - 1][j].critical_mass)
            f(board[i - 1][j]);
        board[i][j - 1].orbs++;
        board[i][j - 1].player = turn;
        if (board[i][j - 1].orbs == board[i][j - 1].critical_mass)
            f(board[i][j - 1]);
        board[i + 1][j].orbs++;
        board[i + 1][j].player = turn;
        if (board[i + 1][j].orbs == board[i + 1][j].critical_mass)
            f(board[i + 1][j]);
        board[i][j + 1].orbs++;
        board[i][j + 1].player = turn;
        if (board[i][j + 1].orbs == board[i][j + 1].critical_mass)
            f(board[i][j + 1]);
    }
}

int main(){
    int i, j;
    int counter = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            board[i][j].row = i;
            board[i][j].column = j;
        }
    }
    board[0][0].critical_mass = 2;
    board[8][0].critical_mass = 2;
    board[0][5].critical_mass = 2;
    board[8][5].critical_mass = 2;
    for (int j = 1; j < 5; j++)
    {
        board[0][j].critical_mass = 3;
        board[8][j].critical_mass = 3;
    }
    for (int i = 1; i < 8; i++)
    {
        board[i][0].critical_mass = 3;
        board[i][5].critical_mass = 3;
    }
    for (int i = 1; i < 8; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            board[i][j].critical_mass = 4;
        }
    }
    while (true)
    {
        cin >> i;
        if (i == -1)
            break;
        cin >> j;
        counter++;
        if (i < 0 || i > 8 || j < 0 || j > 5)
        {
            counter--;
            cout << "Illegal move" << endl;
            continue;
        }
        else if (board[i][j].orbs == 0)
        {
            board[i][j].orbs++;
            if (counter % 2 == 0)
            {
                board[i][j].player = -1;
            }
            else
                board[i][j].player = 1;
        }
        else
        {
            if (counter % 2 == 0 && board[i][j].player == -1)
            {
                board[i][j].orbs++;
                if (board[i][j].orbs == board[i][j].critical_mass)
                {
                    f(board[i][j]);
                }
            }
            else if (counter % 2 == 1 && board[i][j].player == 1)
            {
                board[i][j].orbs++;
                if (board[i][j].orbs == board[i][j].critical_mass)
                {
                    f(board[i][j]);
                }
            }
            else if ((counter % 2 == 0 && board[i][j].player == 1) || (counter % 2 == 1 && board[i][j].player == -1))
            {
                counter--;
                cout << "Illegal move" << endl;
                continue;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << board[i][j].player * board[i][j].orbs << " ";
            }
            cout << board[i][5].player * board[i][5].orbs << endl;
        }
        if (counter > 2 && counter % 2 == 1)
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (board[i][j].player == 1 || board[i][j].player == 0)
                        continue;
                    else
                        goto inwhile;
                }
            }
            break;
        }
        else
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (board[i][j].player == -1 || board[i][j].player == 0)
                        continue;
                    else
                        goto inwhile;
                }
            }
            break;
        }
    inwhile:
        continue;
    }
}