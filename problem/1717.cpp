#include <iostream>
using namespace std;

int u[1000001];
int n, m;

int find(int a) {
	if (u[a] == -1) return a;
	else return u[a] = find(u[a]);
}

void makeUnion(int a, int b) {
	int aRoot = find(a), bRoot = find(b);
	if (aRoot == bRoot) return;
	u[aRoot] = bRoot;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i <= n; ++i) {
		u[i] = -1;
	}
	for (int i = 0; i < m; ++i) {
		int uni, a, b;
		cin >> uni >> a >> b;
		if (uni == 0) {
			makeUnion(a, b);
		}
		else {
			if (find(a) == find(b)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}

	return 0;
}