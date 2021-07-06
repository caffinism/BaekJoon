#include <iostream>
#include <algorithm>
using namespace std;

int cur[3], ma[3], mi[3], ma_pre[3], mi_pre[3];

int main() {
	int n, Max = 0, Min = 10000000;
	cin >> n;
	cin >> mi[0] >> mi[1] >> mi[2];
	ma_pre[0] = mi_pre[0] = ma[0] = mi[0];
	ma_pre[1] = mi_pre[1] = ma[1] = mi[1];
	ma_pre[2] = mi_pre[2] = ma[2] = mi[2];

	for (int i = 1; i < n; ++i) {
		cin >> cur[0] >> cur[1] >> cur[2];

		ma[0] = max(ma_pre[0], ma_pre[1]) + cur[0];
		ma[1] = max(ma_pre[0], max(ma_pre[1], ma_pre[2])) + cur[1];
		ma[2] = max(ma_pre[1], ma_pre[2]) + cur[2];

		mi[0] = min(mi_pre[0], mi_pre[1]) + cur[0];
		mi[1] = min(mi_pre[0], min(mi_pre[1], mi_pre[2])) + cur[1];
		mi[2] = min(mi_pre[1], mi_pre[2]) + cur[2];

		ma_pre[0] = ma[0];
		ma_pre[1] = ma[1];
		ma_pre[2] = ma[2];

		mi_pre[0] = mi[0];
		mi_pre[1] = mi[1];
		mi_pre[2] = mi[2];
	}

	Max = max(ma[0], max(ma[1], ma[2]));
	Min = min(mi[0], min(mi[1], mi[2]));
	cout << Max << ' ' << Min << endl;

	return 0;
}