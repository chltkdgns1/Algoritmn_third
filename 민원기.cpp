#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <queue>
using namespace std;
class bullet {
public:
	int x;
	int y;
	int dir;
	int ran;
};
void gotoxy(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
void cursor(int n) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int Charmove(char ch, int &x, int &y) {
	gotoxy(x, y);
	cout << " ";
	int dir = 0; // 1:상 2:하 3:좌 4:우
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
	if (dir == 1)
		return 1;
	else if (dir == 2)
		return 2;
	else if (dir == 3)
		return 3;
	else if (dir == 4)
		return 4;
}
void BulletMove(queue <bullet> &r) {
	int n = r.size();
	if (n == 0) return;
	for (int i = 0; i < n; i++) {
		int x = r.front().x, y = r.front().y, dir = r.front().dir, ran = r.front().ran;
		if (!ran) {
			gotoxy(x, y), cout << " ";
		}
		else if (ran == 20) {
			gotoxy(x + 1, y);
			cout << "-";
		}
		else {
			gotoxy(x, y);
			cout << " ";
			gotoxy(x + 1, y);
			cout << "-";
		}
		r.pop();
		ran--;
		if (ran >= 0) r.push({ x + 1,y,dir,ran});
	}
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
	char ch; // 입력된 _getch 값
	int Ft;  // 처음시간
	int Lt;  // 나중시간
	int dir = 0;
	int ran = 20;
	queue <bullet> B;
	bool ispush = false;
	cursor(0);
	gotoxy(x, y);
	cout << "*";
	Ft = GetTickCount();
	map();
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' || ch == 'w' || ch == 's' || ch == 'd') dir = Charmove(ch, x, y);
			//wasd 움직임
			if (ch == 'e') {
				//총알 생성 
				B.push({ x,y,dir,ran });
			}
			if (ch == 'q') break; // q입력시 프로그램 종료
		}
		Lt = GetTickCount();
		if (Lt - Ft >= 50) {
			BulletMove(B);
			Ft = Lt;
		}
		//총알 움직임
	}
	gotoxy(0, 24);
	cout << "프로그램을 종료합니다.\n\n\n";
	system("pause");
	return 0;
}