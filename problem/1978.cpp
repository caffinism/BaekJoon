#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> arr;
	bool check[1001] = { false, };
	int n, max = 0, sum = 0;
	cin >> n;

	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i] > max) max = arr[i];
	}
	check[1] = true;
	for (int i = 2; i <= max; ++i) {
		for (int j = 2; j * i <= max; ++j) {
			check[i * j] = true;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (check[arr[i]] == false) sum++;
	}

	cout << sum;

	return 0;
}