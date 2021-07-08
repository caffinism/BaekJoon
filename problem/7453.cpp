#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	long long a[4000], b[4000], c[4000], d[4000], cnt = 0;
	vector<long long> ab, cd;
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ab.push_back(a[i] + b[j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cd.push_back(c[i] + d[j]);
		}
	}
	sort(cd.begin(), cd.end());

	for (int i = 0; i < ab.size(); ++i) {
		long long d = 0 - ab[i];
		cnt += upper_bound(cd.begin(), cd.end(), d) - lower_bound(cd.begin(), cd.end(), d);
	}
	
	cout << cnt;

	return 0;
}