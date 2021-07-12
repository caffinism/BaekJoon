#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
int u[1001];
vector<pair<int, pair<int, int>>> node;

int find(int x) {
	if (u[x] == -1) return x;
	else return u[x] = find(u[x]);
}

void makeUnion(int x, int y) {
	int xRoot = find(x);
	int yRoot = find(y);
	if (x == y) return;
	u[xRoot] = yRoot;
}

void kruskal() {
	for (int i = 0; i < m; ++i) {
		int a = node[i].second.first;
		int b = node[i].second.second;

		if (find(a) != find(b)) {
			makeUnion(a, b);
			ans += node[i].first;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		node.push_back(make_pair(c, make_pair(a, b)));
	}
	
	sort(node.begin(), node.end());

	for (int i = 0; i <= n; ++i) {
		u[i] = -1;
	}

	kruskal();
	cout << ans;

	return 0;
}