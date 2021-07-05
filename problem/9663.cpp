#include <iostream>

using namespace std;

int n, cnt;
int check[15];

void dfs(int v) {
	int flag;
	if (v == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; ++i) {
		flag = 1;
		for (int j = 0; j < v; ++j) {
			//i열에 퀸이 있는지 체크
			//또는 대각선에 퀸이 있는지 체크
			if (check[j] == i || abs(v - j) == abs(i - check[j])) {
				flag = 0;
				break;
			}
		}
		//flag가 0이면 i열에 퀸 놓지 못함
		if (flag == 1) {
			check[v] = i;
			dfs(v + 1);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	dfs(0);

	cout << cnt;

	return 0;
}