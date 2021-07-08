#include <iostream>
using namespace std;

int n, m;
int arr[10];

void dfs(int v, int idx) {
	if (v == m) {
		for (int i = 0; i < 10; ++i) {
			if (arr[i] == 1) {
				cout << i << ' ';
			}
		}cout << '\n';
	}
	else {
		for (int i = idx+1; i <= n; ++i) {
			if (arr[i] == 0) {
				arr[i] = 1;
				dfs(v + 1, i);
				arr[i] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(0, 0);
	return 0;
}