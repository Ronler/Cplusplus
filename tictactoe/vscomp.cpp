// Aaron Miller
// Engr 30
// Program 7.15

#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;

void fill(int&);
void table();
int check();
char board[3][3] = { { '*', '*', '*' },
{ '*', '*', '*' },
{ '*', '*', '*' } };

int main()
{
	int player = 1;

	do
	{
		table();
		fill(player);
		check();

	} while (check() == -1);

	if (check() == 1)
		cout << "player 1 wins!!\n\n";
	else if (check() == 2)
		cout << "Player 2 wins!!\n\n";
	else if (check() == 3)
		cout << "Tie game...\n\n";

	system("pause");
	EXIT_SUCCESS;
}

void table()
{
	system("cls");

	cout << "\tTic Tac Toe Game.\n"
		<< "Player 1 (X) \t Player 2 (O)\n\n";
	cout << "     1    2     3 \n\n";
	cout << "       |     |    \n";
	cout << "1   " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
	cout << "   ____|_____|____\n";
	cout << "       |     |    \n";
	cout << "2   " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
	cout << "   ____|_____|____\n";
	cout << "       |     |    \n";
	cout << "3   " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
	cout << "       |     |    \n";

}

void fill(int &player)
{
	srand(time(NULL));

	char move;
	if (player % 2 == 1)
		move = 'X';
	else
		move = 'O';

	int row, column;

	if (move == 'X')
	{
		cout << "Player  " << "  (" << move << ")\n";
		cout << "Row: ";
		cin >> row;
		cout << "Column: ";
		cin >> column;
		cout << endl;
	}
	else if (move == 'O')
	{
		row = rand() % 3 + 1;
		column = rand() % 3 + 1;
	}

	if (row == 1 && column == 1 && board[0][0] == '*')
		board[0][0] = move;
	else if (row == 1 && column == 2 && board[0][1] == '*')
		board[0][1] = move;
	else if (row == 1 && column == 3 && board[0][2] == '*')
		board[0][2] = move;
	else if (row == 2 && column == 1 && board[1][0] == '*')
		board[1][0] = move;
	else if (row == 2 && column == 2 && board[1][1] == '*')
		board[1][1] = move;
	else if (row == 2 && column == 3 && board[1][2] == '*')
		board[1][2] = move;
	else if (row == 3 && column == 1 && board[2][0] == '*')
		board[2][0] = move;
	else if (row == 3 && column == 2 && board[2][1] == '*')
		board[2][1] = move;
	else if (row == 3 && column == 3 && board[2][2] == '*')
		board[2][2] = move;
	else
	{
		cout << "Move is not valid.\n";
		cin.get();
		cin.ignore();
		player--;
	}

	player++;

}

int check()
{
	// Check rows for win

	for (int i = 0; i < 2; i++)
	{
		if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
			return 1;
		else if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
			return 2;
	}
	// Check columns for win
	for (int i = 0; i < 2; i++)
	{
		if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
			return 1;
		else if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
			return 2;
	}


	// Check diagonals for player 1 win
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
		return 1;
	if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
		return 1;

	// Check diagonals for player 2 win
	if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
		return 2;
	if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
		return 2;

	// Check for a tie game
	if (board[0][0] != '*' && board[0][1] != '*' && board[0][2] != '*'
		&& board[1][0] != '*' && board[1][1] != '*' && board[1][2] != '*'
		&& board[2][0] != '*' && board[2][1] != '*' && board[2][2] != '*')
		return 3;
	else
		return -1;
}