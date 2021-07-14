#include <iostream>
using namespace std;


const long long INF = 2000000000;
long long d[101][101];
int n, m;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c < d[a][b]) {
			d[a][b] = c;
		}
	}

	// 플로이드 와샬
	for (int k = 1; k <= n; ++k) { // k 거쳐가는 노드
		for (int i = 1; i <= n; ++i) { // i 출발 노드
			for (int j = 1; j <= n; ++j) { // j 도착 노드
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] == INF) {
				cout << 0 << ' ';
			}
			else {
				cout << d[i][j] << ' ';
			}
		}cout << '\n';
	}

	return 0;
}