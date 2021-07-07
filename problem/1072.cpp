#include <iostream>
using namespace std;

int main() {
	long long x, y, z, nextZ;

	cin >> x >> y;
	z = y *100 / x;
	if (z == 100 || z == 99) {
		cout << -1;
		return 0;
	}

	long long l = 0, r = 1000000000, mid, ans = 1000000000;
	
	while (l <= r) {
		mid = (l + r) / 2;
		nextZ = (y + mid) * 100 / (x + mid);
		if (z < nextZ) {
			if (mid < ans) {
				ans = mid;
			}
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans;

	return 0;
}