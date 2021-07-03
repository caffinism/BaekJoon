#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y) {
	while (1) {
		int temp = y;
		y = x % y;
		x = temp;
		if (y == 0) break;
	}
	return x;
}

int main() {
	int t;
	cin >> t;

	for (int test = 0; test < t; ++test) {
		vector<int> arr;
		int n;
		long sum = 0;
		cin >> n;
		arr.resize(n);

		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				sum += gcd(arr[i], arr[j]);
			}
		}

		cout << sum << '\n';
	}

	return 0;
}