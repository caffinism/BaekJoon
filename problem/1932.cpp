#include <iostream>
using namespace std;

int main() {
	int n, Max = 0;
	int before[501] = { 0, }, after[501] = { 0, };
	cin >> n;
	cin >> before[0];
	if (n == 1) {
		cout << before[0];
		return 0;
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			cin >> after[j];
			if (j == 0) {
				after[j] += before[0];
			}
			else if (j == i - 1) {
				after[j] += before[j - 1];
			}
			else {
				after[j] += max(before[j - 1], before[j]);
			}
		}
		for (int j = 0; j < i; ++j) {
			before[j] = after[j];
		}
	}
	for (int i = 0; i < n; ++i) {
		if (Max < after[i]) {
			Max = after[i];
		}
	}
	cout << Max;
	return 0;
}