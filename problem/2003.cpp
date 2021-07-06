#include <iostream>
using namespace std;

int main() {
	int n, m, a[10001];
	int sum = 0, start = 0, end = 0, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	while (1) {
		while (end < n && sum < m) {
			sum += a[end++];
		}
		if (sum < m) {
			break;
		}
		if (sum == m) {
			cnt++;
		}
		sum -= a[start++];
	}
	cout << cnt;
	return 0;
}