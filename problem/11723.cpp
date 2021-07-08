#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int m, val;
	int set[21] = { 0, };
	string str;

	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> str;
		if (str == "add") {
			cin >> val;
			set[val] = 1;
		}
		else if (str == "remove") {
			cin >> val;
			set[val] = 0;
		}
		else if (str == "check") {
			cin >> val;
			if (set[val] == 1) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (str == "toggle") {
			cin >> val;
			if (set[val] == 0) {
				set[val] = 1;
			}
			else {
				set[val] = 0;
			}
		}
		else if (str == "all") {
			for (int i = 1; i <= 20; ++i) {
				set[i] = 1;
			}
		}
		else if (str == "empty") {
			for (int i = 1; i <= 20; ++i) {
				set[i] = 0;
			}
		}
	}
	return 0;
}