//未实现：兵升变；重新选择移动的棋子；王车易位；
#define SHOW_CONSOLE
#include<iostream>
#include<cmath>
#include<string>
#include<map>
#include<graphics.h>
using namespace std;
static enum Stringvalue
{
	Notdefined,
	Pawn1, Pawn2, Pawn3, Pawn4, Pawn5, Pawn6, Pawn7, Pawn8,
	Rook1, Rook2, Knight1, Knight2, Bishop1, Bishop2,
	Queen1, King1
};
static map<string, Stringvalue>Transtrvalues;
static string Input;
static void Initialize()
{
	Transtrvalues["p1"] = Pawn1;
	Transtrvalues["p2"] = Pawn2;
	Transtrvalues["p3"] = Pawn3;
	Transtrvalues["p4"] = Pawn4;
	Transtrvalues["p5"] = Pawn5;
	Transtrvalues["p6"] = Pawn6;
	Transtrvalues["p7"] = Pawn7;
	Transtrvalues["p8"] = Pawn8;
	Transtrvalues["r1"] = Rook1;
	Transtrvalues["r2"] = Rook2;
	Transtrvalues["h1"] = Knight1;
	Transtrvalues["h2"] = Knight2;
	Transtrvalues["b1"] = Bishop1;
	Transtrvalues["b2"] = Bishop2;
	Transtrvalues["q1"] = Queen1;
	Transtrvalues["k1"] = King1;
}
char board[8][8] = { 0 };
int ju[8][8] = { 0 };
int Mark[8][8] = { 0 };
string Name[8][8] = { "0" };
mouse_msg msg = { 0 };
PIMAGE pp[33];
static int pn = 0;
static int nn = 32;
/*mouse_msg GETM()
{
for (; is_run(); delay_fps(60))
{
while(mousemsg())

}
}*/
class Chess
{
protected:
	int row;
	int col;
	char val;
	int flag;
	string name;
public:
	virtual void move() = 0;
};
class Pawn :public Chess
{
public:
	Pawn(int r, int c, int f, string n);
	void move();
};
class Knight :public Chess
{
public:
	Knight(int r, int c, int f, string n);
	void move();
};
class Bishop :public Chess
{
public:
	Bishop(int r, int c, int f, string n);
	void move();
};
class Rook :public Chess
{
public:
	Rook(int r, int c, int f, string n);
	void move();
};
class Queen :public Chess
{
public:
	Queen(int r, int c, int f, string n);
	void move();
};
class King :public Chess
{
public:
	King(int r, int c, int f, string n);
	void move();
	friend bool IfCheck(King &k);
	friend bool Isover(King &k);
};
Pawn::Pawn(int r, int c, int f, string n)
{
	col = c;
	row = r;
	flag = f;
	val = 'P';
	name = n;
	board[row][col] = val;
	ju[row][col] = flag;
}
void Pawn::move()
{

	int x, y;
	if (flag == 1)
		while (true)
		{
			for (; is_run(); delay_fps(60))
			{
				mouse_msg m1 = { 0 };
				while (mousemsg())
					m1 = getmouse();
				if (m1.is_left() && m1.is_up())
				{
					y = m1.x / 80;
					x = m1.y / 80;
					break;
				}
			}
			flushmouse();
			if (x - row == 2 && board[x][y] == 0 && board[x - 1][y] == 0 && y == col && row == 1)
			{
				board[row][col] = 0;
				ju[row][col] = 0;
				Name[row][col] = "0";
				row = x;
				col = y;
				board[x][y] = 'P';
				ju[x][y] = flag;
				Name[x][y] = name;
				break;
			}
			else if (x - row == 1 && board[x][y] == 0 && y == col)
			{
				board[row][col] = 0;
				ju[row][col] = 0;
				Name[row][col] = "0";
				row = x;
				col = y;
				board[x][y] = 'P';
				ju[x][y] = flag;
				Name[x][y] = name;
				break;
			}
			else if (x - row == 1 && abs(y - col) == 1 && ju[x][y] == 2)
			{
				board[row][col] = 0;
				ju[row][col] = 0;
				Name[row][col] = "0";
				row = x;
				col = y;
				board[x][y] = 'P';
				ju[x][y] = flag;
				Name[x][y] = name;
				break;
			}
			else if (x - row == 1 && abs(y - col) == 1 && ju[row][y] == 2 && row == 4 && board[row][y] == 'P')
			{
				board[row][y] = 0;
				ju[row][y] = 0;
				Name[row][col] = "0";
				row = x;
				col = y;
				board[x][y] = 'P';
				ju[x][y] = flag;
				Name[x][y] = name;
				break;
			}
			else
				cout << "chongxinshuru ";
		}
	else
		while (true)
		{
			mouse_msg m1 = { 0 };
			for (; is_run(); delay_fps(60))
			{
				while (mousemsg())
					m1 = getmouse();
				if (m1.is_left() && m1.is_up())
				{
					y = m1.x / 80;
					x = m1.y / 80;
					break;
				}
			}
			flushmouse();

			if (row - x == 2 && board[x][y] == 0 && board[x + 1][y] == 0 && y == col && row == 6)
			{
				board[row][col] = 0;
				ju[row][col] = 0;
				Name[row][col] = "0";
				row = x;
				col = y;
				board[x][y] = 'P';
				ju[x][y] = flag;
				Name[x][y] = name;
				break;
			}
			else if (row - x == 1 && board[x][y] == 0 && y == col)
			{
				board[row][col] = 0;
				ju[row][col] = 0;
				Name[row][col] = "0";
				row = x;
				col = y;
				board[x][y] = 'P';
				ju[x][y] = flag;
				Name[x][y] = name;
				break;
			}
			else if (row - x == 1 && abs(y - col) == 1 && ju[x][y] == 1)
			{
				board[row][col] = 0;
				ju[row][col] = 0;
				Name[row][col] = "0";
				row = x;
				col = y;
				board[x][y] = 'P';
				ju[x][y] = flag;
				Name[x][y] = name;
				break;
			}
			else if (row - x == 1 && abs(y - col) == 1 && ju[row][y] == 1 && row == 3 && board[row][y] == 'P')
			{
				board[row][y] = 0;
				ju[row][y] = 0;
				Name[row][col] = "0";
				row = x;
				col = y;
				board[x][y] = 'P';
				ju[x][y] = flag;
				Name[x][y] = name;
				break;
			}
			else
				cout << "chongxinshuru";
		}
}
bool Canmove1(int i, int j, int x, int y, int s)
{
	if (s == ju[i][j])
		return false;
	if (ju[i][j] == 1)
	{
		if (x - i == 2 && board[x][y] == 0 && board[x - 1][y] == 0 && y == j && i == 1)
			return true;
		if (x - i == 1 && board[x][y] == 0 && y == j)
			return true;
		if (x - i == 1 && abs(y - j) == 1 && s == 2)
			return true;
		if (x - i == 1 && abs(y - j) == 1 && ju[i][y] == 2 && i == 4 && board[i][y] == 'P')
			return true;
	}
	if (ju[i][j] == 2)
	{
		if (i - x == 2 && board[x][y] == 0 && board[x + 1][y] == 0 && y == j && i == 6)
			return true;
		if (i - x == 1 && board[x][y] == 0 && y == j)
			return true;
		if (i - x == 1 && abs(y - j) == 1 && s == 1)
			return true;
		if (i - x == 1 && abs(y - j) == 1 && ju[i][y] == 1 && i == 3 && board[i][y] == 'P')
			return true;
	}
	return false;
}
Knight::Knight(int r, int c, int f, string n)
{
	row = r;
	col = c;
	val = 'H';
	flag = f;
	name = n;
	board[row][col] = val;
	ju[row][col] = flag;
}
void Knight::move()
{
	mouse_msg m1 = { 0 };
	int x, y;
	while (true)
	{
		for (; is_run(); delay_fps(60))
		{
			while (mousemsg())
				m1 = getmouse();
			if (m1.is_left() && m1.is_up())
			{
				y = m1.x / 80;
				x = m1.y / 80;
				break;
			}
		}
		if (abs(x - row) == 1 && abs(y - col) == 2 && ju[x][y] != flag)
		{
			board[row][col] = 0;
			ju[row][col] = 0;
			Name[row][col] = "0";
			row = x;
			col = y;
			board[x][y] = 'K';
			ju[x][y] = flag;
			Name[x][y] = name;
			break;
		}
		else if (abs(x - row) == 2 && abs(y - col) == 1 && ju[x][y] != flag)
		{
			board[row][col] = 0;
			ju[row][col] = 0;
			Name[row][col] = "0";
			row = x;
			col = y;
			board[x][y] = 'K';
			ju[x][y] = flag;
			Name[x][y] = name;
			break;
		}
		else
			cout << "chongxinshuru";
	}
}
bool Canmove2(int i, int j, int x, int y, int s)
{
	if (!ju[i][j])
		return false;
	if (abs(x - i) == 1 && abs(y - j) == 2 && s != ju[i][j])
		return true;
	if (abs(x - i) == 2 && abs(y - j) == 1 && s != ju[i][j])
		return true;
	return false;
}
Bishop::Bishop(int r, int c, int f, string n)
{
	row = r;
	col = c;
	val = 'B';
	flag = f;
	name = n;
	board[row][col] = val;
	ju[row][col] = flag;
}
void Bishop::move()
{
	mouse_msg m1 = { 0 };
	int x, y;
	while (true)
	{
		for (; is_run(); delay_fps(60))
		{
			while (mousemsg())
				m1 = getmouse();
			if (m1.is_left() && m1.is_up())
			{
				y = m1.x / 80;
				x = m1.y / 80;
				break;
			}
		}
		flushmouse();
		if (abs(x - row) == abs(y - col) && ju[x][y] != flag)
		{
			int i, j;
			int t = (y - col) / abs(y - col);
			int q = (x - row) / abs(x - row);
			for (i = t, j = q; row + j != x; i += t, j += q)
				if (board[row + j][col + i] != 0)
				{
					cout << "chongxinshuru";
					break;
				}
			if (row + j == x)
			{
				board[row][col] = 0;
				ju[row][col] = 0;
				Name[row][col] = "0";
				row = x;
				col = y;
				board[x][y] = 'B';
				ju[x][y] = flag;
				Name[x][y] = name;
				break;
			}
		}
		else
			cout << "chongxinshuru";
	}
}
bool Canmove3(int i, int j, int x, int y, int s)
{
	if (!ju[i][j])
		return false;
	if (abs(x - i) == abs(y - j) && s != ju[i][j])
	{
		int k, p;
		int t = (y - j) / abs(y - j);
		int q = (x - i) / abs(x - i);
		for (k = t, p = q; i + p != x; k += t, p += q)
			if (board[i + p][j + k] != 0)
				break;
		if (i + p == x)
			return true;
	}
	return false;
}
Rook::Rook(int r, int c, int f, string n)
{
	row = r;
	col = c;
	flag = f;
	val = 'R';
	name = n;
	board[row][col] = val;
	ju[row][col] = flag;
}
void Rook::move()
{
	mouse_msg m1 = { 0 };
	int x, y;
	while (true)
	{
		for (; is_run(); delay_fps(60))
		{
			while (mousemsg())
				m1 = getmouse();
			if (m1.is_left() && m1.is_up())
			{
				y = m1.x / 80;
				x = m1.y / 80;
				break;
			}
		}
		flushmouse();
		if (x == row && y != col && ju[row][col] != ju[x][y])
		{
			int i;
			int t = (y - col) / abs(y - col);
			for (i = t; (col + i) != y; i += t)
				if (board[row][col + i] != 0)
					break;
			if (col + i == y)
			{
				board[row][col] = 0;
				ju[row][col] = 0;
				Name[row][col] = "0";
				row = x;
				col = y;
				board[x][y] = 'R';
				ju[x][y] = flag;
				Name[x][y] = name;
				break;
			}
		}
		else if (y == col && x != row && ju[row][col] != ju[x][y])
		{
			int i;
			int t = (x - row) / abs(x - row);
			for (i = t; (row + i) != x; i += t)
				if (board[row + i][col] != 0)
					break;
			if (row + i == x)
			{
				board[row][col] = 0;
				ju[row][col] = 0;
				Name[row][col] = "0";
				row = x;
				col = y;
				board[x][y] = 'R';
				ju[x][y] = flag;
				Name[x][y] = name;
				break;
			}
		}
		else
			cout << "chongxinshuru";
	}
}
bool Canmove4(int i, int j, int x, int y, int s)
{
	if (!ju[i][j])
		return false;
	if (x == i && y != j && ju[i][j] != s)
	{
		int k;
		int t = (y - j) / abs(y - j);
		for (k = t; (j + k) != y; k += t)
			if (board[i][j + k] != 0)
				break;
		if (j + k == y)
			return true;
	}
	if (y == j && x != i && ju[i][j] != s)
	{
		int k;
		int t = (x - i) / abs(x - i);
		for (k = t; (i + k) != x; k += t)
			if (board[i][j + k] != 0)
				break;
		if (i + k == x)
			return true;
	}
	return false;
}
Queen::Queen(int r, int c, int f, string n)
{
	row = r;
	col = c;
	val = 'Q';
	flag = f;
	name = n;
	board[row][col] = val;
	ju[row][col] = flag;
}
void Queen::move()
{
	int x, y;
	mouse_msg m1 = { 0 };
	while (true)
	{
		for (; is_run(); delay_fps(60))
		{
			while (mousemsg())
				m1 = getmouse();
			if (m1.is_left() && m1.is_up())
			{
				y = m1.x / 80;
				x = m1.y / 80;
				break;
			}
		}
		flushmouse();
		if (x == row && y != col)
		{
			int i;
			int t = (y - col) / abs(y - col);
			for (i = t; (col + i) != y; i += t)
				if (board[row][col + i] != 0)
					break;
			if (col + i == y)
			{
				board[row][col] = 0;
				ju[row][col] = 0;
				Name[row][col] = "0";
				row = x;
				col = y;
				board[x][y] = 'Q';
				ju[x][y] = flag;
				Name[x][y] = name;
				break;
			}
		}
		else if (y == col && x != row)
		{
			int i;
			int t = (x - row) / abs(x - row);
			for (i = t; (row + i) != x; i += t)
				if (board[row + i][col] != 0)
					break;
			if (row + i == x)
			{
				board[row][col] = 0;
				ju[row][col] = 0;
				Name[row][col] = "0";
				row = x;
				col = y;
				board[x][y] = 'Q';
				ju[x][y] = flag;
				Name[x][y] = name;

				break;
			}
		}
		if (abs(x - row) == abs(y - col) && ju[x][y] != flag)
		{
			int i, j;
			int t = (y - col) / abs(y - col);
			int q = (x - row) / abs(x - row);
			for (i = t, j = q; row + j != x; i += t, j += q)
				if (board[row + j][col + i] != 0)
					break;
			if (row + j == x)
			{
				board[row][col] = 0;
				ju[row][col] = 0;
				Name[row][col] = "0";
				row = x;
				col = y;
				board[x][y] = 'Q';
				ju[x][y] = flag;
				Name[x][y] = name;
				i = t;
				break;
			}
		}
		else
			cout << "chongxinshuru";
	}
}
bool Canmove5(int i, int j, int x, int y, int s)
{
	if (!ju[i][j])
		return false;
	if (x == i && y != j && ju[i][j] != s)
	{
		int k;
		int t = (y - j) / abs(y - j);
		for (k = t; (j + k) != y; k += t)
			if (board[i][j + k] != 0)
				break;
		if (j + k == y)
			return true;
	}
	if (y == j && x != i && ju[i][j] != s)
	{
		int k;
		int t = (x - i) / abs(x - i);
		for (k = t; (i + k) != x; k += t)
			if (board[i][j + k] != 0)
				break;
		if (i + k == x)
			return true;
	}
	if (abs(x - i) == abs(y - j) && s != ju[i][j])
	{
		int k, p;
		int t = (y - j) / abs(y - j);
		int q = (x - i) / abs(x - i);
		for (k = t, p = q; i + p != x; k += t, p += q)
			if (board[i + p][j + k] != 0)
				break;
		if (i + p == x)
			return true;
	}
	return false;
}
King::King(int r, int c, int f, string n)
{
	row = r;
	col = c;
	val = 'K';
	flag = f;
	name = n;
	board[row][col] = val;
	ju[row][col] = flag;
}
void King::move()
{
	mouse_msg m1 = { 0 };
	int x, y;
	while (true)
	{
		for (; is_run(); delay_fps(60))
		{
			while (mousemsg())
				m1 = getmouse();
			if (m1.is_left() && m1.is_up())
			{
				y = m1.x / 80;
				x = m1.y / 80;
				break;
			}
		}
		flushmouse();
		if (((abs(x - row) == 1 && abs(y - col) == 1) || (y == col && abs(x - row) == 1) || (x == row && abs(y - col) == 1)) && ju[x][y] != flag)
		{
			board[row][col] = 0;
			ju[row][col] = 0;
			Name[row][col] = "0";
			row = x;
			col = y;
			board[x][y] = 'K';
			ju[x][y] = flag;
			Name[x][y] = name;
			break;
		}
		else
			cout << "chongxinshuru";
	}
}
bool Canmove6(int i, int j, int x, int y, int s)
{
	if (!ju[i][j])
		return false;
	if (x < 0 || x>7 || y < 0 || y>7)
		return false;
	if (((abs(x - i) == 1 && abs(y - j) == 1) || (y == j && abs(x - i) == 1) || (x == i && abs(y - j) == 1)) && s != ju[i][j])
		return true;
	return false;
}
bool Canget(int i, int j, int x, int y, int p)
{
	if (i == x && j == y)
		return false;
	if (ju[i][j] == p)
		return false;
	switch (board[i][j])
	{
	case 'P':
		return Canmove1(i, j, x, y, p);
	case 'H':
		return Canmove2(i, j, x, y, p);
	case 'B':
		return Canmove3(i, j, x, y, p);
	case 'R':
		return Canmove4(i, j, x, y, p);
	case 'Q':
		return Canmove5(i, j, x, y, p);
	case 'K':
		return Canmove6(i, j, x, y, p);
	}
	return false;
}
bool Canbee(int i, int j)
{
	for (int p = 0; p < 8; p++)
	{
		for (int q = 0; q < 8; q++)
		{
			if (Canget(p, q, i, j, ju[i][j]))
				return true;
		}
	}
	return false;
}
bool Canbee(int i, int j, int p)
{
	for (int p = 0; p < 8; p++)
	{
		for (int q = 0; q < 8; q++)
		{
			if (Canget(p, q, i, j, ju[i][j]) && board[p][q] != 'K')
				return true;
		}
	}
	return false;
}

bool IfEat(int i, int j, int p, int q)
{
	if (ju[i][j] + ju[p][q] == 3)
		return true;
	else
		return false;
}
bool Isover(King &k)
{
	int flag = 0;
	int  i, j, t = 0, count = 0;
	int ex[8];
	for (i = 0; i < 8; i++)
		ex[i] = 0;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			if (Canget(i, j, k.row, k.col, k.flag))
			{
				cout << i << j << k.row << k.col;;
				t = 1;
				if (Canbee(i, j, 0))
					return false;
			}
	if (t)
	{
		if (k.row + 1 >= 0 && k.row + 1 <= 7 && Canmove6(k.row, k.col, k.row + 1, k.col, ju[k.row + 1][k.col]))
		{
			count++;
			cout << 1 << endl;
			for (i = 0; i < 8; i++)
				for (j = 0; j < 8; j++)
					if (Canget(i, j, k.row + 1, k.col, k.flag))
						ex[count - 1] = 1;

		}
		if (k.row - 1 >= 0 && k.row - 1 <= 7 && Canmove6(k.row, k.col, k.row - 1, k.col, ju[k.row - 1][k.col]))
		{
			cout << 2 << endl;
			count++;
			for (i = 0; i < 8; i++)
				for (j = 0; j < 8; j++)
					if (Canget(i, j, k.row - 1, k.col, k.flag))
						ex[count - 1] = 1;
		}
		if (k.col + 1 >= 0 && k.col + 1 <= 7 && Canmove6(k.row, k.col, k.row, k.col + 1, ju[k.row][k.col + 1]))
		{
			count++;
			cout << 9 << endl;
			for (i = 0; i < 8; i++)
				for (j = 0; j < 8; j++)
					if (Canget(i, j, k.row, k.col + 1, k.flag))
						ex[count - 1] = 1;
		}
		if (k.col - 1 >= 0 && k.col - 1 <= 7 && Canmove6(k.row, k.col, k.row, k.col - 1, ju[k.row][k.col - 1]))
		{
			count++;
			cout << 4 << endl << Canmove6(k.row, k.col, k.row, k.col - 1, ju[k.row][k.col - 1]);
			for (i = 0; i < 8; i++)
				for (j = 0; j < 8; j++)
					if (Canget(i, j, k.row, k.col - 1, k.flag))
						ex[count - 1] = 1;
		}
		if (k.row + 1 >= 0 && k.row + 1 <= 7 && k.col - 1 >= 0 && k.col - 1 <= 7 && Canmove6(k.row, k.col, k.row + 1, k.col - 1, ju[k.row + 1][k.col - 1]))
		{
			count++;
			cout << 5 << endl;
			for (i = 0; i < 8; i++)
				for (j = 0; j < 8; j++)
					if (Canget(i, j, k.row + 1, k.col - 1, k.flag))
						ex[count - 1] = 1;
		}
		if (k.row + 1 >= 0 && k.row + 1 <= 7 && k.col + 1 >= 0 && k.col + 1 <= 7 && Canmove6(k.row, k.col, k.row + 1, k.col + 1, ju[k.row + 1][k.col + 1]))
		{
			count++;
			cout << 6 << endl<<count;
			for (i = 0; i < 8; i++)
			{
				for (j = 0; j < 8; j++)
				{
					cout << i << j;
					if (Canget(i, j, k.row + 1, k.col + 1, k.flag))
					{
						Canget(i, j, k.row + 1, k.col + 1, k.flag);
						ex[count - 1] = 1;
						for (int p = 0; p < count; p++)
							cout << ex[p];
					}
				}
			}
		}
		if (k.row - 1 >= 0 && k.row - 1 <= 7 && k.col - 1 >= 0 && k.col - 1 <= 7 && Canmove6(k.row, k.col, k.row - 1, k.col - 1, ju[k.row - 1][k.col - 1]))
		{
			count++;
			cout << 7 << endl;
			for (i = 0; i < 8; i++)
				for (j = 0; j < 8; j++)
					if (Canget(i, j, k.row - 1, k.col - 1, k.flag))
						ex[count - 1] = 1;
		}
		if (k.row - 1 >= 0 && k.row - 1 <= 7 && k.col + 1 >= 0 && k.col + 1 <= 7 && Canmove6(k.row, k.col, k.row - 1, k.col + 1, ju[k.row - 1][k.col + 1]))
		{
			count++;
			cout << 8 << endl;
			for (i = 0; i < 8; i++)
				for (j = 0; j < 8; j++)
					if (Canget(i, j, k.row - 1, k.col + 1, k.flag))
						ex[count - 1] = 1;
		}
	}
	else
		return false;
	cout << count;

	for (i = 0; i < count; i++)
	{
		cout << ex[i];
		if (!ex[i])
			break;
	}
	cout << count << i;
	if (i == count)
		return true;
	else
		return false;
}
void Print()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == 0)
				cout << ". ";
			else
				cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}
void InitString(string s[8][8])
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			s[i][j] = "0";
	s[0][0] = "r1";		s[0][1] = "h1";		s[0][2] = "b1";		s[0][3] = "q1";		s[0][4] = "k1";		s[0][5] = "b2";		s[0][6] = "h2";		s[0][7] = "r2";
	s[1][0] = "p1";		s[1][1] = "p2";		s[1][2] = "p3";		s[1][3] = "p4";		s[1][4] = "p5";		s[1][5] = "p6";		s[1][6] = "p7";		s[1][7] = "p8";
	s[6][0] = "p1";		s[6][1] = "p2";		s[6][2] = "p3";		s[6][3] = "p4";		s[6][4] = "p5";		s[6][5] = "p6";		s[6][6] = "p7";		s[6][7] = "p8";
	s[7][0] = "r1";		s[7][1] = "h1";		s[7][2] = "b1";		s[7][3] = "q1";		s[7][4] = "k1";		s[7][5] = "b2";		s[7][6] = "h2";		s[7][7] = "r2";
}
void InitG()
{
	int i = 1;
	pp[0] = newimage();
	getimage(pp[0], "f:\\Pieces\\board.png");
	putimage(0, 0, pp[0]);
	for (; i < 9; i++)
	{
		pp[i] = newimage();
		getimage(pp[i], "f:\\Pieces\\p1.png");
		putimage_withalpha(NULL, pp[i], 80 * i - 80, 80);
	}
	for (; i < 17; i++)
	{
		pp[i] = newimage();
		getimage(pp[i], "f:\\Pieces\\p2.png");
		putimage_withalpha(NULL, pp[i], 80 * i - 720, 480);
	}
	pp[17] = newimage();		getimage(pp[17], "f:\\Pieces\\r1.png");		putimage_withalpha(NULL, pp[17], 0, 0);
	pp[18] = newimage();		getimage(pp[18], "f:\\Pieces\\r1.png");		putimage_withalpha(NULL, pp[18], 560, 0);
	pp[19] = newimage();		getimage(pp[19], "f:\\Pieces\\r2.png");		putimage_withalpha(NULL, pp[19], 0, 560);
	pp[20] = newimage();		getimage(pp[20], "f:\\Pieces\\r2.png");		putimage_withalpha(NULL, pp[20], 560, 560);
	pp[21] = newimage();		getimage(pp[21], "f:\\Pieces\\k1.png");		putimage_withalpha(NULL, pp[21], 80, 0);
	pp[22] = newimage();		getimage(pp[22], "f:\\Pieces\\k1.png");		putimage_withalpha(NULL, pp[22], 480, 0);
	pp[23] = newimage();		getimage(pp[23], "f:\\Pieces\\k2.png");		putimage_withalpha(NULL, pp[23], 80, 560);
	pp[24] = newimage();		getimage(pp[24], "f:\\Pieces\\k2.png");		putimage_withalpha(NULL, pp[24], 480, 560);
	pp[25] = newimage();		getimage(pp[25], "f:\\Pieces\\b1.png");		putimage_withalpha(NULL, pp[25], 160, 0);
	pp[26] = newimage();		getimage(pp[26], "f:\\Pieces\\b1.png");		putimage_withalpha(NULL, pp[26], 400, 0);
	pp[27] = newimage();		getimage(pp[27], "f:\\Pieces\\b2.png");		putimage_withalpha(NULL, pp[27], 160, 560);
	pp[28] = newimage();		getimage(pp[28], "f:\\Pieces\\b2.png");		putimage_withalpha(NULL, pp[28], 400, 560);
	pp[29] = newimage();		getimage(pp[29], "f:\\Pieces\\q1.png");		putimage_withalpha(NULL, pp[29], 240, 0);
	pp[30] = newimage();		getimage(pp[30], "f:\\Pieces\\q2.png");		putimage_withalpha(NULL, pp[30], 240, 560);
	pp[31] = newimage();		getimage(pp[31], "f:\\Pieces\\ki1.png");	putimage_withalpha(NULL, pp[31], 320, 0);
	pp[32] = newimage();		getimage(pp[32], "f:\\Pieces\\ki2.png");	putimage_withalpha(NULL, pp[32], 320, 560);

}
void Show()
{
	cleardevice();
	int q = 1;
	getimage(pp[0], "f:\\Pieces\\board.png");
	putimage(0, 0, pp[0]);
	for (int i = 0; i<8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (ju[i][j] == 1)
			{
				switch (Transtrvalues[Name[i][j]])
				{
				case Pawn1:
					getimage(pp[q], "f:\\Pieces\\p1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Pawn2:
					getimage(pp[q], "f:\\Pieces\\p1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Pawn3:
					getimage(pp[q], "f:\\Pieces\\p1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Pawn4:
					getimage(pp[q], "f:\\Pieces\\p1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Pawn5:
					getimage(pp[q], "f:\\Pieces\\p1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Pawn6:
					getimage(pp[q], "f:\\Pieces\\p1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Pawn7:
					getimage(pp[q], "f:\\Pieces\\p1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Pawn8:
					getimage(pp[q], "f:\\Pieces\\p1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Rook1:
					getimage(pp[q], "f:\\Pieces\\r1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Rook2:
					getimage(pp[q], "f:\\Pieces\\r1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Knight1:
					getimage(pp[q], "f:\\Pieces\\k1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Knight2:
					getimage(pp[q], "f:\\Pieces\\k1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Bishop1:
					getimage(pp[q], "f:\\Pieces\\b1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Bishop2:
					getimage(pp[q], "f:\\Pieces\\b1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Queen1:
					getimage(pp[q], "f:\\Pieces\\q1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case King1:
					getimage(pp[q], "f:\\Pieces\\ki1.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				}
			}
			else if (ju[i][j] == 2)
			{
				switch (Transtrvalues[Name[i][j]])
				{
				case Pawn1:
					getimage(pp[q], "f:\\Pieces\\p2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Pawn2:
					getimage(pp[q], "f:\\Pieces\\p2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Pawn3:
					getimage(pp[q], "f:\\Pieces\\p2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Pawn4:
					getimage(pp[q], "f:\\Pieces\\p2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Pawn5:
					getimage(pp[q], "f:\\Pieces\\p2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Pawn6:
					getimage(pp[q], "f:\\Pieces\\p2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Pawn7:
					getimage(pp[q], "f:\\Pieces\\p2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Pawn8:
					getimage(pp[q], "f:\\Pieces\\p2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Rook1:
					getimage(pp[q], "f:\\Pieces\\r2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Rook2:
					getimage(pp[q], "f:\\Pieces\\r2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Knight1:
					getimage(pp[q], "f:\\Pieces\\k2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Knight2:
					getimage(pp[q], "f:\\Pieces\\k2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Bishop1:
					getimage(pp[q], "f:\\Pieces\\b2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Bishop2:
					getimage(pp[q], "f:\\Pieces\\b2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case Queen1:
					getimage(pp[q], "f:\\Pieces\\q2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				case King1:
					getimage(pp[q], "f:\\Pieces\\ki2.png");	putimage_withalpha(NULL, pp[q], 80 * j, 80 * i);
					q++;
					break;
				}
			}
		}
}
int main()
{
	cout << "输入";
	initgraph(640, 640);
	InitG();
	Initialize();
	InitString(Name);
	setfont(40, 0, "宋体");
	/*PIMAGE board = newimage();
	getimage(board, "f:\\Pieces\\board.png");
	putimage(0, 0, board);
	PIMAGE pp1 = newimage();		getimage(pp1, "f:\\Pieces\\p1.png");		putimage_withalpha(NULL, pp1, 0, 80);
	PIMAGE pp2 = newimage();		getimage(pp1, "f:\\Pieces\\p1.png");		putimage_withalpha(NULL, pp1, 80, 80);
	PIMAGE pp3 = newimage();		getimage(pp1, "f:\\Pieces\\p1.png");		putimage_withalpha(NULL, pp1, 160, 80);
	PIMAGE pp4 = newimage();		getimage(pp1, "f:\\Pieces\\p1.png");		putimage_withalpha(NULL, pp1, 240, 80);
	PIMAGE pp5 = newimage();		getimage(pp1, "f:\\Pieces\\p1.png");		putimage_withalpha(NULL, pp1, 320, 80);
	PIMAGE pp6 = newimage();		getimage(pp1, "f:\\Pieces\\p1.png");		putimage_withalpha(NULL, pp1, 400, 80);
	PIMAGE pp7 = newimage();		getimage(pp1, "f:\\Pieces\\p1.png");		putimage_withalpha(NULL, pp1, 480, 80);
	PIMAGE pp8 = newimage();		getimage(pp1, "f:\\Pieces\\p1.png");		putimage_withalpha(NULL, pp1, 560, 80);
	PIMAGE pp9 = newimage();		getimage(pp1, "f:\\Pieces\\p2.png");		putimage_withalpha(NULL, pp1, 0, 480);
	PIMAGE pp10 = newimage();		getimage(pp1, "f:\\Pieces\\p2.png");		putimage_withalpha(NULL, pp1, 80, 480);
	PIMAGE pp11 = newimage();		getimage(pp1, "f:\\Pieces\\p2.png");		putimage_withalpha(NULL, pp1, 160, 480);
	PIMAGE pp12 = newimage();		getimage(pp1, "f:\\Pieces\\p2.png");		putimage_withalpha(NULL, pp1, 240, 480);
	PIMAGE pp13 = newimage();		getimage(pp1, "f:\\Pieces\\p2.png");		putimage_withalpha(NULL, pp1, 320, 480);
	PIMAGE pp14 = newimage();		getimage(pp1, "f:\\Pieces\\p2.png");		putimage_withalpha(NULL, pp1, 400, 480);
	PIMAGE pp15 = newimage();		getimage(pp1, "f:\\Pieces\\p2.png");		putimage_withalpha(NULL, pp1, 480, 480);
	PIMAGE pp16 = newimage();		getimage(pp1, "f:\\Pieces\\p2.png");		putimage_withalpha(NULL, pp1, 560, 480);
	PIMAGE rp1 = newimage();		getimage(pp1, "f:\\Pieces\\r1.png");		putimage_withalpha(NULL, pp1, 0, 0);
	PIMAGE rp2 = newimage();		getimage(pp1, "f:\\Pieces\\r1.png");		putimage_withalpha(NULL, pp1, 560, 0);
	PIMAGE rp3 = newimage();		getimage(pp1, "f:\\Pieces\\r2.png");		putimage_withalpha(NULL, pp1, 0, 560);
	PIMAGE rp4 = newimage();		getimage(pp1, "f:\\Pieces\\r2.png");		putimage_withalpha(NULL, pp1, 560, 560);
	PIMAGE kp1 = newimage();		getimage(pp1, "f:\\Pieces\\k1.png");		putimage_withalpha(NULL, pp1, 80, 0);
	PIMAGE kp2 = newimage();		getimage(pp1, "f:\\Pieces\\k1.png");		putimage_withalpha(NULL, pp1, 480, 0);
	PIMAGE kp3 = newimage();		getimage(pp1, "f:\\Pieces\\k2.png");		putimage_withalpha(NULL, pp1, 80, 560);
	PIMAGE kp4 = newimage();		getimage(pp1, "f:\\Pieces\\k2.png");		putimage_withalpha(NULL, pp1, 480, 560);
	PIMAGE bp1 = newimage();		getimage(pp1, "f:\\Pieces\\b1.png");		putimage_withalpha(NULL, pp1, 160, 0);
	PIMAGE bp2 = newimage();		getimage(pp1, "f:\\Pieces\\b1.png");		putimage_withalpha(NULL, pp1, 400, 0);
	PIMAGE bp3 = newimage();		getimage(pp1, "f:\\Pieces\\b2.png");		putimage_withalpha(NULL, pp1, 160, 560);
	PIMAGE bp4 = newimage();		getimage(pp1, "f:\\Pieces\\b2.png");		putimage_withalpha(NULL, pp1, 400, 560);
	PIMAGE qp1 = newimage();		getimage(pp1, "f:\\Pieces\\q1.png");		putimage_withalpha(NULL, pp1, 240, 0);
	PIMAGE qp2 = newimage();		getimage(pp1, "f:\\Pieces\\q2.png");		putimage_withalpha(NULL, pp1, 240, 560);
	PIMAGE kip1 = newimage();		getimage(pp1, "f:\\Pieces\\ki1.png");		putimage_withalpha(NULL, pp1, 320, 0);
	PIMAGE kip2 = newimage();		getimage(pp1, "f:\\Pieces\\ki2.png");		putimage_withalpha(NULL, pp1, 320, 560);
	*/


	Pawn p1(1, 0, 1, "p1"), p2(1, 1, 1, "p2"), p3(1, 2, 1, "p3"), p4(1, 3, 1, "p4"), p5(1, 4, 1, "p5"), p6(1, 5, 1, "p6"), p7(1, 6, 1, "p7"), p8(1, 7, 1, "p8");
	Pawn p9(6, 0, 2, "p1"), p10(6, 1, 2, "p2"), p11(6, 2, 2, "p3"), p12(6, 3, 2, "p4"), p13(6, 4, 2, "p5"), p14(6, 5, 2, "p6"), p15(6, 6, 2, "p7"), p16(6, 7, 2, "p8");
	Rook r1(0, 0, 1, "r1"), r2(0, 7, 1, "r2"), r3(7, 0, 2, "r1"), r4(7, 7, 2, "r2");
	Knight k1(0, 1, 1, "h1"), k2(0, 6, 1, "h2"), k3(7, 1, 2, "h1"), k4(7, 6, 2, "h2");
	Bishop b1(0, 2, 1, "b1"), b2(0, 5, 1, "b2"), b3(7, 2, 2, "b1"), b4(7, 5, 2, "b2");
	Queen q1(0, 3, 1, "q1"), q2(7, 3, 2, "q1");
	King ki1(0, 4, 1, "k1"), ki2(7, 4, 2, "k1");
	Print();
	Chess *po;
	int turn = 1;
	int x, y;
	while (!Isover(ki1) && !Isover(ki2))
	{
		for (; is_run(); delay_fps(60))
		{
			while (mousemsg())
			{
				msg = getmouse();
			}
			if (msg.is_up() && msg.is_left())
			{
				y = msg.x / 80;
				x = msg.y / 80;
				break;
			}
		}
		Input = Name[x][y];
		flushmouse();


		if (ju[x][y] == 0)
			continue;
		turn = !turn;
		if (turn)
		{
			switch (Transtrvalues[Input])
			{
			case Pawn1:
				po = &p1;
				po->move();
				break;
			case Pawn2:
				po = &p2;
				po->move();
				break;
			case Pawn3:
				po = &p3;
				po->move();
				break;
			case Pawn4:
				po = &p4;
				po->move();
				break;
			case Pawn5:
				po = &p5;
				po->move();
				break;
			case Pawn6:
				po = &p6;
				po->move();
				break;
			case Pawn7:
				po = &p7;
				po->move();
				break;
			case Pawn8:
				po = &p8;
				po->move();
				break;
			case Rook1:
				po = &r1;
				po->move();
				break;
			case Rook2:
				po = &r2;
				po->move();
				break;
			case Knight1:
				po = &k1;
				po->move();
				break;
			case Knight2:
				po = &k2;
				po->move();
				break;
			case Bishop1:
				po = &b1;
				po->move();
				break;
			case Bishop2:
				po = &b2;
				po->move();
				break;
			case Queen1:
				po = &q1;
				po->move();
				break;
			case King1:
				po = &ki1;
				po->move();
				break;
			default:
				cout << "请重新输入：";
			}
		}
		else
		{
			switch (Transtrvalues[Input])
			{
			case Pawn1:
				po = &p9;
				po->move();
				break;
			case Pawn2:
				po = &p10;
				po->move();
				break;
			case Pawn3:
				po = &p11;
				po->move();
				break;
			case Pawn4:
				po = &p12;
				po->move();
				break;
			case Pawn5:
				po = &p13;
				po->move();
				break;
			case Pawn6:
				po = &p14;
				po->move();
				break;
			case Pawn7:
				po = &p15;
				po->move();
				break;
			case Pawn8:
				po = &p16;
				po->move();
				break;
			case Rook1:
				po = &r3;
				po->move();
				break;
			case Rook2:
				po = &r4;
				po->move();
				break;
			case Knight1:
				po = &k3;
				po->move();
				break;
			case Knight2:
				po = &k4;
				po->move();
				break;
			case Bishop1:
				po = &b3;
				po->move();
				break;
			case Bishop2:
				po = &b4;
				po->move();
				break;
			case Queen1:
				po = &q2;
				po->move();
				break;
			case King1:
				po = &ki2;
				po->move();
				break;
			default:
				cout << "请重新输入: ";

			}
		}
		Show();

		Print();
	}
	if (Isover(ki1))
	{
		xyprintf(0, 0, "The White win");
	}
	else
	{
		xyprintf(0, 0, "The Black win");
	}
	getch();
	for (int i = 0; i < 33; i++)
		delimage(pp[i]);
	closegraph();
	system("pause");
}