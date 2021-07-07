#include <iostream>
#include <deque>
using namespace std;

typedef pair<int, int> pii;
deque<pii> dq;
int n, l, val;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;

	for (int i = 0; i < n; ++i) {
		cin >> val;
		while (!dq.empty()) {
			pii t = dq.back();
			if (t.second >= val) dq.pop_back();
			else break;
		}
		dq.push_back(pii(i, val));
		pii t = dq.front();
		if (t.first == i - l) dq.pop_front(), t = dq.front();
		cout << t.second << ' ';
	}

	return 0;
}