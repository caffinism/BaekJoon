#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> graph[100001];
int ancient[100001];

void makeTree(int cur, int parent) {
	ancient[cur] = parent;

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (next != parent) {
			makeTree(next, cur);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	makeTree(1, 0); // 1번을 루트로 하는 트리 생성

	for (int i = 2; i <= n; ++i) {
		cout << ancient[i] << '\n';
	}

	return 0;
}