#include <iostream>
using namespace std;

int main() {
	int n, s, a[100001], start = 0, end = 0, cnt = 0, sum = 0, Min = 100000;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	while (1) {
		while (end < n && sum < s) {
			sum += a[end++];
		}
		if (sum < s) break;
		cnt++;
		if (end - start< Min) {
			Min = end - start;
		}
		sum -= a[start++];
	}
	if (cnt == 0) {
		cout << 0;
	}
	else {
		cout << Min;
	}

	return 0;
}