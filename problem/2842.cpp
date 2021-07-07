#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, h[50][50], dy[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int cnt_k, y_post, x_post;
char vil[50][51];
vector<int> hhh;

int bfs(int low, int high) {
	int cnt = 0;
	bool vt[50][50] = { false, };
	if (low > h[y_post][x_post] || h[y_post][x_post] > high) {
		return 0;
	}
	queue<pii> q;
	q.push(pii(y_post, x_post));
	vt[y_post][x_post] = true;
	while (!q.empty() && cnt < cnt_k) {
		pii cur = q.front();
		q.pop();
		for (int i = 0; i < 8; ++i) {
			int nexty = cur.first + dy[i];
			int nextx = cur.second + dx[i];
			if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= n) continue;
			if (vt[nexty][nextx]) continue;
			if (h[nexty][nextx]<low || h[nexty][nextx]>high) continue;
			if (vil[nexty][nextx] == 'K') {
				cnt++;
			}
			vt[nexty][nextx] = true;
			q.push(pii(nexty, nextx));
		}
	}

	return cnt;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> vil[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> h[i][j];
			hhh.push_back(h[i][j]);
			if (vil[i][j] == 'K') cnt_k++;
			else if (vil[i][j] == 'P') {
				y_post = i;
				x_post = j;
			}
		}
	}

	sort(hhh.begin(), hhh.end());
	int ans = hhh.back() - hhh[0];
	for (int low = 0, high = 0; low < hhh.size() && high < hhh.size() && low <= high;) {
		if (bfs(hhh[low], hhh[high]) == cnt_k) {
			int tmp = hhh[high] - hhh[low];
			if (tmp < ans) {
				ans = tmp;
			}
			low++;
		}
		else {
			high++;
		}
	}

	cout << ans;
	return 0;
}