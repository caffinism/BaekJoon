#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> arr[32001];
int degree[32001];

void topologySort() {
	queue<int> q;
	vector<int> vec;

	for (int i = 1; i <= n; ++i) {
		if (degree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= n; ++i) {
		int v = q.front();
		q.pop();
		vec.push_back(v);
		for (int i = 0; i < arr[v].size(); ++i) {
			int cur = arr[v][i];
			degree[cur] -= 1;
			if (degree[cur] == 0) {
				q.push(cur);
			}
		}
	}
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		degree[b]++;
	}

	topologySort();

	return 0;
}