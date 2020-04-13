#include <iostream>
#include <string>
#include <conio.h>
#include <io.h>
#include <fstream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	_finddata_t fd;
	long hand;
	int res = 1;
	string a = "C:\\Users\\chltk\\source\\repos\\", b = "\\*.sln";
	string w = a + "*.*";
	hand = _findfirst(w.c_str(), &fd);

	if (hand == -1) {
		//cout << "there is no file" << "\n";
		return 0;
	}

	while (res != -1) {

		int r = 1;
		long hd2;
		_finddata_t fd2;
		string t = a; 
		t += fd.name, t += b;
		hd2 = _findfirst(t.c_str(), &fd2);

		if (hd2 == -1) {
			res = _findnext(hand, &fd);
			continue;
		}
		
		while (r != -1) {
			string d = fd.name, d2 = fd2.name, rs;

			for (int i = 0; i < 4; i++) d2.pop_back();
			ifstream in(a + d + "\\" + d2 + "\\main.cpp");

			ofstream ot;
			ot.open(d2 + ".cpp");

			if (ot.is_open()) {
				cout << "output success" << "\n";
				char c;
				while ((c = in.get()) != EOF) rs += c;
				ot << rs;
			}

			r = _findnext(hd2, &fd2);
		}

		res = _findnext(hand, &fd);
	}

	_findclose(hand);
	system("pause");
}