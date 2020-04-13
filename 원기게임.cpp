#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
char ch[4] = { 'l','l','-','-' };
char wasd[4] = { 'w','s','a','d' };
//몬스터 클래스
class monster {
public:
	int x, y;
};
class bullet {
public:
	int x, y, dir, ran;
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
	gotoxy(x, y), cout << " ";
	for (int i = 0; i < 4; i++) {
		if (wasd[i] == ch) {
			x += dx[i], y += dy[i];
			// x 또는y 가 범위에 나가면 x -= dx[i] ,y -= dy[i] goto return i 
			gotoxy(x, y); cout << "*";
			return i;
		}
	}
}

void BulletMove(queue <bullet> &r) {
	int n = r.size();
	if (n == 0) return;
	for (int i = 0; i < n; i++) {
		int x = r.front().x, y = r.front().y, dir = r.front().dir, ran = r.front().ran;
		r.pop();
		if (!ran) {
			gotoxy(x, y);
			cout << " ";
			continue;
		}
		if (ran == 20) {
			gotoxy(x, y);
			cout << ch[dir];
		}
		else {
			gotoxy(x, y);
			cout << " ";
			x += dx[dir], y += dy[dir];
			gotoxy(x, y);
			cout << ch[dir];
		}
		r.push({ x,y,dir,--ran });
	}
}
void map() {
	for (int i = 0; i < 51; i++) {
		gotoxy(i, 0);
		cout << "%";
		gotoxy(i, 20);
		cout << "%";
	}
	for (int i = 0; i < 20; i++) {
		gotoxy(0, i);
		cout << "%";
		gotoxy(50, i);
		cout << "%";
	}
}
monster MonsterCreate() {
	return { rand() % 49 + 1,rand() % 19 + 1 };
}

void MonsterPrint(monster mon) {
	gotoxy(mon.x, mon.y);
	cout << "M";
}
/*
void MonsterMove(monster mon) {

}
*/
int main(void) {
	srand(time(NULL));
	int x = 1, y = 1;
	char ch; // 입력된 _getch 값
	int Ft;  // 처음시간
	int Lt1, Lt2;// , Lt3;  // 나중시간
	int dir = 0;
	int cnt = 0;
	int Cnt;
	int ut;
	//int mt;
	queue <bullet> q;
	monster Mon[100];
	cursor(0);
	gotoxy(x, y);
	cout << "*";
	Ft = GetTickCount();
	ut = GetTickCount();
	//mt = GetTickCount();
	map();
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' || ch == 'w' || ch == 's' || ch == 'd') dir = Charmove(ch, x, y);
			if (ch == 'e') q.push({ x + dx[dir],y + dy[dir] ,dir,18 });
			if (ch == 'q') break; // q입력시 프로그램 종료
		}
		Lt1 = GetTickCount();
		if (Lt1 - Ft >= 50) { //총알움직임
			BulletMove(q);
			Ft = Lt1;
		}
		Lt2 = GetTickCount();
		if (Lt2 - ut >= 1000 && cnt < 100) { //몬스터 생성
			for (int i = 0; i < 5; i++) {
				Mon[cnt++] = MonsterCreate();
			}
			for (int i = cnt - 5; i < cnt; i++) {
				MonsterPrint(Mon[i]);
			}
			ut = Lt2;
		}
		/*
		Lt3 = GetTickCount();
		if (Lt3 - mt >= 500) {
			
		}
		*/
	}
	gotoxy(0, 24);
	cout << "프로그램을 종료합니다.\n\n\n";
	system("pause");
	return 0;
}

/*



*/