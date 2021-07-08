#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int > pii;

int n, num;
pii player[500000];
int tr[2000000];

int seg_sum(int node, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return tr[node];
	}
	else {
		return seg_sum(node * 2, s, (s + e) / 2, l, r) + seg_sum(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
	}
}

void update(int node, int s, int e, int idx, int v) {
	if (idx < s || e < idx) return;
	if (s == e) {
		tr[node] = v;
	}
	else {
		update(node * 2, s, (s + e) / 2, idx, v);
		update(node * 2 + 1, (s + e) / 2 + 1, e, idx, v);
		tr[node] = tr[node * 2] + tr[node * 2 + 1];
	}

}

bool cmp(pii p1, pii p2) {
	return p1.second < p2.second;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int power;
		cin >> power;
		player[i].first = i;
		player[i].second = power;
	}

	sort(player, player + n, cmp);

	for (int i = 0; i < n; ++i) {
		player[i].second = ++num;
	}//labeling

	sort(player, player + n);
	
	for (int i = 0; i < n; ++i) {
		int curpower = player[i].second;
		int cnt = 0;
		if (curpower > 1) {
			cnt = seg_sum(1, 1, num, 1, curpower - 1);
		}
		update(1, 1, num, curpower, 1);
		cout << i + 1 - cnt << '\n';
	}

	return 0;
}