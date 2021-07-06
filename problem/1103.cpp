#include <iostream>
using namespace std;

int n, m, res, Max;
char map[51][51];
int check[51][51];
int cache[51][51];
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };

int dfs(int x, int y) {
	int flag, temp;
	flag = 0;
	for (int i = 0; i < 4; ++i) {
		int next_x, next_y;
		next_x = x + dx[i] * (map[x][y]-'0');
		next_y = y + dy[i] * (map[x][y]-'0');
		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && map[next_x][next_y]!='H') {
			flag = 1;
			if (check[next_x][next_y] != 0) {
				res = -1;
				return -1;
			}
			check[next_x][next_y] = 1;
			if (cache[next_x][next_y] > 0) {
				temp = cache[next_x][next_y] + 1;
			}
			else {
				temp = dfs(next_x, next_y) + 1;
			}
			if (temp > cache[x][y]) {
				cache[x][y] = temp;
			}
			check[next_x][next_y] = 0;
		}
	}
	if (flag == 0) {
		cache[x][y] = 1;
		return 1;
	}
	else {
		return cache[x][y];
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}
	check[0][0] = 1;
	dfs(0, 0);
	if (res == -1) {
		cout << -1;
		return 0;
	}
	cout << cache[0][0];
	return 0;
}