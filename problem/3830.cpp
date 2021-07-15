#include <iostream>
using namespace std;

int n, m;
int u[100001];
long long d[100001];

int find(int a) {
	if (u[a] == a) {
		return a;
	}
	find(u[a]);
	d[a] += d[u[a]];
	return u[a] = find(u[a]);
}

void makeUnion(int a, int b, int dist) {
	int aRoot = find(a);
	int bRoot = find(b);

	if (aRoot == bRoot) return;

	d[bRoot] = d[a] - d[b] + dist;

	u[bRoot] = aRoot;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		for (int i = 0; i <= n; ++i) {
			u[i] = i;
			d[i] = 0;
		}

		for (int i = 0; i < m; ++i) {
			char ch;
			int a, b;
			cin >> ch >> a >> b;
			if (ch == '!') {
				int d;
				cin >> d;
				makeUnion(a, b, d);
			}
			else {
				if (find(a) == find(b)) {
					cout << d[b] - d[a] << '\n';
				}
				else {
					cout << "UNKNOWN\n";
				}
			}
		}
	}
	return 0;
}