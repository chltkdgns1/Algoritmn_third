#include <iostream>
#include <string>
using namespace std;


// STring Ŭ������ ���� �Է��� �޾ƺ���

class String {
private:
	char *str; //�ּҰ��� �����ϴ� ����
	int len;
public:

	void setStr(char *a) {
		str = a;
		for (len = 0; str[len] != NULL; len++);
	}

	void push_back(char a) {
		str[len++] = a;
	}

	char *getStr() {
		return str;
	}

	void printStr() {
		for (int i = 0; str[i] != 0; i++)
			cout << str[i];
	}

	int length() {
		return len;
	}
};

String str;

void init() {
	char a[30];
	cin >> a;
	str.setStr(a);
	str.printStr();
}

int main() {
	init();
	str.printStr();
	system("pause");
}