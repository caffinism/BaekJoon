#include <iostream>

using namespace std;

bool check[1000000] = { false, };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	check[1] = true;
	for (int i = 2; i <= 1000000; ++i) {
		if (check[i] == true) continue;
		for (int j = 2; i * j <= 1000000; ++j) {
			check[i * j] = true;
		}
	}

	while (1) {
		int n, a, b, flag;
		cin >> n;

		if (n == 0) break;

		flag = 0;
		for (int i = 1; i <= n/2; i+=2) {
			a = i;
			b = n - i;
			if (check[a] == false && check[b] == false) {
				cout << n << " = " << a << " + " << b << '\n';
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}
	return 0;
}