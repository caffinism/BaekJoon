#include <iostream>
using namespace std;


const int INF = 10000;
int d[501][501], cnt[501];
int n, m, ans;

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
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;
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
			if (i == j) continue;
			if (d[i][j] < INF) {
				cnt[i]++;
				cnt[j]++;
				if (cnt[i] == n - 1) ans++;
				if (cnt[j] == n - 1) ans++;
			}
		}
	}

	cout << ans;

	return 0;
}