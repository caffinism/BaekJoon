#include <iostream>
using namespace std;

int n, m;
int parent[201];

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find(parent[a]);
}

void makeUnion(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);

	if (aRoot == bRoot) return;

	parent[aRoot] = bRoot;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i <= n; ++i) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int a;
			cin >> a;
			if (a == 1) {
				makeUnion(i, j);
			}
		}
	}

	int tmp, tRoot;
	cin >> tmp;
	tRoot = find(tmp);

	for (int i = 1; i <m; ++i) {
		cin >> tmp;
		if (tRoot != find(tmp)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}