#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <queue>
#include <time.h>
using namespace std;

int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

class bullet {
public:
	int x, y, dir, dis;
};

class monster {
public:
	int x, y;
};

void gotoxy(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
void cursor(int n) { //커서 보이기 & 숨기기
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void move(char ch, int &x, int &y,int &dir) {
	gotoxy(x, y);
	cout << " ";
	switch (ch) {
	case 'w':
		if (y > 1) y--;
		dir = 1;
		break;
	case 's':
		if (y < 19) y++;
		dir = 2;
		break;
	case 'a':
		if (x > 1) x--;
		dir = 3;
		break;
	case 'd':
		if (x < 49) x++;
		dir = 4;
		break;
	}
	gotoxy(x, y);
	cout << "*";
}

void CreateMissile(int &x, int &y, int &dir, queue <bullet> &bul) {
	if (y == 1 && dir == 1) return;
	if (x == 1 && dir == 3) return;
	if (x == 49 && dir == 4) return;
	if (y == 19 && dir == 2) return;
	bul.push({ x + dx[dir - 1] ,y + dy[dir - 1],dir,20 });
	gotoxy(x + dx[dir - 1], y + dy[dir - 1]);
	cout << "W";
}

void map() {
	for (int i = 0; i < 51; i++) {
		gotoxy(i, 0);
		cout << "%";
	}
	for (int i = 0; i < 51; i++) {
		gotoxy(i, 20);
		cout << "%";
	}
	for (int i = 0; i < 20; i++) {
		gotoxy(0, i);
		cout << "%";
	}
	for (int i = 0; i < 20; i++) {
		gotoxy(50, i);
		cout << "%";
	}
}

int main(void) {
	int x = 1, y = 1;
	char ch;
	int Mdir = 0;
	int dir = 0;
	queue <bullet> qbul;
	queue <monster> mbul;

	srand(time(0));

	cursor(0);
	gotoxy(x, y);
	cout << "*";
	map();
	int time = GetTickCount(); // 10분 
	int mtime = GetTickCount();
	int movemon = GetTickCount();
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' || ch == 'w' || ch == 's' || ch == 'd') move(ch, x, y,dir);
			if (ch == 'e') CreateMissile(x, y, dir,qbul); // 미사일이 생성됨
			if (ch == 'q') break;
		}

		int u = GetTickCount();

		if (u - time >= 100) {
			time = GetTickCount();
			int cnt = qbul.size(), t = 0;
			while (t < cnt) {
				t++;
				int x = qbul.front().x;
				int y = qbul.front().y;
				int dir = qbul.front().dir;
				int dis = qbul.front().dis;
				qbul.pop();

				if (!dis || (x == 1 && dir == 3) || (y == 1 && dir == 1) ||
					(x >= 49 && dir == 4) || (y >= 19 && dir == 2)) {
					gotoxy(x, y);
					cout << " ";
					continue;
				}
				gotoxy(x, y);
				cout << " ";
				x += dx[dir - 1], y += dy[dir - 1];
				gotoxy(x, y);
				cout << "W";
				dis--;
				qbul.push({ x,y,dir,dis });
			}
		} 		// 미사일이 날아감

		if (u - movemon >= 500) {
			movemon = GetTickCount();
			int m_cnt = mbul.size(), m_t = 0;
			while (m_t < m_cnt) {
				m_t++;
				int dir = rand() % 4;
				int x = mbul.front().x;
				int y = mbul.front().y;
				mbul.pop();
				gotoxy(x, y);
				cout << " ";
				int nx = x + dx[dir], ny = y + dy[dir];
				if (nx >= 1 && ny >= 1 && nx <= 49 && ny <= 19) {
					gotoxy(nx, ny);
					cout << "@";
					mbul.push({ nx,ny });
				}
				else mbul.push({ x,y });
			}
		}
		if (u - mtime >= 250) {
			mtime = GetTickCount();
			int x = rand() % 30 + 1, y = rand() % 10 + 1;
			gotoxy(x, y);
			cout << "@";
			mbul.push({ x,y });
		}
	}
	gotoxy(0, 24);
	cout << "프로그램을 종료합니다.\n\n\n";
	system("pause");
	return 0;
}