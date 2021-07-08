#include <iostream>
using namespace std;

int map[130][130];

int count(int a, int b, int size, int idx) {
	int flag = 0, flag2 = 0;
	for (int i = a; i < a+size; ++i) {
		for (int j = b; j < b+size; ++j) {
			if (map[i][j] != idx) {
				flag = 1;
				break;
			}
		}
	}
	for (int i = a; i < a+size; ++i) {
		for (int j = b; j < b+size; ++j) {
			if (map[i][j] == idx) {
				flag2 = 1;
				break;
			}
		}
	}
	if (flag2 == 0) {
		return 0;
	}
	if (flag == 1) {
		//cout << a << ' ' << b << ' ' << size << '\n';
		return count(a, b, size/2, idx) + count(a+size/2, b, size/2, idx) + count(a, b+size/2, size/2, idx) + count(a+size/2, b+size/2, size/2, idx);
	}
	else {
		return 1;
	}
}

int main() {
	int n;
	int blue_cnt = 0, white_cnt = 0;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}

	blue_cnt = count(0, 0, n, 1);
	white_cnt = count(0, 0, n, 0);

	cout << white_cnt << '\n' << blue_cnt;

	return 0;
}