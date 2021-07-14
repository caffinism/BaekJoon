#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> arr[501];
vector<int> topolArr;
int degree[501];
int cost[501];
int total[501];

void topologySort() {
	queue<int> q;

	for (int i = 1; i <= n; ++i) {
		if (degree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= n; ++i) {
		int v = q.front();
		q.pop();
		topolArr.push_back(v);
		for (int i = 0; i < arr[v].size(); ++i) {
			int cur = arr[v][i];
			degree[cur] -= 1;
			if (degree[cur] == 0) {
				q.push(cur);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int c, pre;
		cin >> c;
		cost[i] = c;
		total[i] = c;
		cin >> pre;
		while (pre != -1) {
			arr[pre].push_back(i);
			degree[i]++;
			cin >> pre;
		}
	}

	topologySort();

	for (int i = 0; i < topolArr.size(); ++i) {
		int cur = topolArr[i];

		for (int j = 0; j < arr[cur].size(); ++j) {
			int next = arr[cur][j];
			total[next] = max(total[next], total[cur] + cost[next]);
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << total[i] << '\n';
	}

	return 0;
}