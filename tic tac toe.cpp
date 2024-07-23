#include <bits/stdc++.h>
using namespace std;
class Score
{
	int score1;
	int score2;

public:
	void updateScore(int a, int b)
	{
		score1 = a;
		score2 = b;
	}
	void displayScore()
	{
		cout << score1 << endl;
		cout << score2 << endl;
	}
};
class Game : public Score
{
	string player1;
	string player2;

public:
	Game(string p1, string p2)
	{
		player1 = p1;
		player2 = p2;
	}
	int arr[3][3];
	int flag = 0;
	void board(void);
	void display(void);
	void logic(void);
	int winner();
};
void Game ::board()
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = 2;
		}
	}
}
void Game ::display()
{
	cout << "Player 1 is " << player1 << endl;
	cout << "Player 2 is " << player2 << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void Game ::logic()
{
	int count = 1;
	while (count <= 9)
	{
		cout << "Enter the empty row no. you want to put x or o" << endl;
		int row;
		cin >> row;
		cout << "Enter the empty col no. you want to put x or o" << endl;
		int col;
		cin >> col;

		if (flag == 0)
		{

			if ((arr[row][col] == 2))
			{

				arr[row][col] = 1;

				count++;
				flag = 1;
				cout << flag << endl;
				int res = winner();
				if (res == 1)
				{
					updateScore(1, 0);
					displayScore();
					break;
				}
			}
		}
		else
		{
			if ((arr[row][col] == 2))
			{
				arr[row][col] = 0;
				count++;
				flag = 0;
				int res = winner();
				if (res == 1)
				{
					break;
				}
			}
		}
		display();
	}
}
int Game ::winner()
{
	if ((arr[0][0] == 1) && (arr[0][1] == 1) && (arr[0][2] == 1))
	{
		cout << "Player 1 " << player1 << "is winner" << endl;

		return 1;
	}
	else if ((arr[0][0] == 0) && (arr[0][1] == 0) && (arr[0][2] == 0))
	{
		cout << "Player 2 " << player1 << "is winner" << endl;
		return 1;
	}

	return 0;
}
int main()
{
	cout << "Enter the name of player 1" << endl;
	string p1;
	cin >> p1;
	cout << "Enter the name of player 2" << endl;
	string p2;
	cin >> p2;
	Game g(p1, p2);
	g.board();
	g.display();
	g.logic();
}