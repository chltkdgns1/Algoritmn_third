#include <iostream>
#include <string>
using namespace std;

string str[5] = { 
"\"����Լ��� ������?\"",
"\"�� ����.�������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���."
,"���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.",
"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"",
"��� �亯�Ͽ���."
};

void solve(int n,string under) {
	if (!n) {
		cout << under + str[0] << "\n";
		cout << under + "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		cout << under + str[4] << "\n";
		return;
	}
	for (int i = 0; i < 4; i++) cout << under + str[i] << "\n";
	solve(n - 1,under + "____");
	cout << under + str[4] << "\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	solve(n,"");
	system("pause");
}