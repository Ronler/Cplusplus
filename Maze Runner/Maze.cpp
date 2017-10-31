#include<iostream>
#include<fstream>
using namespace std;

bool solve(int, int, char[][20]);
void print(char[][20], int, int);
int start_row, start_col;
int row, col;
int end_row = 0, end_col;

int main()
{

	ifstream Maze;
	Maze.open("C:\\Users\\aaron\\Desktop\\maze_file2.txt");  // Change file location to match your computer
	Maze >> row;
	Maze >> col;

	char maze[40][20];

	while (!Maze.eof())
	{
		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
			{
				Maze >> maze[r][c];
			}
		}
	}
	Maze.close();

	start_row = row - 1;

	for (int k = 0; k < col; k++)
	{
		if (maze[row - 1][k] == 'o')
		{
			maze[row - 1][k] = '*';
			k = start_col;
		}
	}

	for (int j = 0; j < col; j++)
	{
		if (maze[0][j] == 'o')
		{
			j = end_col;
		}
	}

	solve(start_row, start_col, maze);

		cout << "\n I'm Out!\n";

	cin.get();
	return 0;

}

void print(char maze[][20], int r, int c)
{
	system("cls");

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << maze[i][j];
		}
		cout << endl;
	}
}

bool solve(int x, int y, char maze[][20])
{
	maze[x][y] = '*';

	print(maze, row, col);

	if (maze[x][y + 1] == 'o' && solve(x, y + 1, maze))
	{
		return true;
	}

	else if (maze[x - 1][y] == 'o' && solve(x - 1, y, maze))
	{
		return true;
	}

	else if (maze[x][y - 1] == 'o' && solve(x, y - 1, maze))
	{
		return true;
	}

	else if (maze[x + 1][y] == 'o' && solve(x + 1, y, maze))
	{
		return true;
	}

	else if (maze[x][y] == maze[end_row][end_col])
	{
		return true;
	}

	maze[x][y] = '.';
	print(maze, row, col);
	return false;

}

