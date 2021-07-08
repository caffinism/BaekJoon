#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long t, cnt = 0;
	int n, m;
	int a[1000], b[1000];
	vector<long long> a_sum, b_sum;

	cin >> t >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	for (int i = 0; i < n; ++i) {
		long long sum = a[i];
		a_sum.push_back(sum);
		for (int j = i + 1; j < n; ++j) {
			sum += a[j];
			a_sum.push_back(sum);
		}
	}

	for (int i = 0; i < m; ++i) {
		long long sum = b[i];
		b_sum.push_back(sum);
		for (int j = i + 1; j < m; ++j) {
			sum += b[j];
			b_sum.push_back(sum);
		}
	}
	sort(b_sum.begin(), b_sum.end());

	for (int i = 0; i < a_sum.size(); ++i) {
		long long d = t - a_sum[i];
		cnt += upper_bound(b_sum.begin(), b_sum.end(), d) - lower_bound(b_sum.begin(), b_sum.end(), d);
	}

	cout << cnt;

	return 0;
}