#include <iostream>
using namespace std;

long long powFunc(long long a, long long b, long long c) {
	long long ans = 1;
	while (b) {
		if (b & 1) {
			ans = (ans*(a%c))%c;
		}
		a = ((a % c) * (a % c)) % c;
		b /= 2;
	}

	return (int)ans;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long a, b, c;
	cin >> a >> b >> c;

	cout << powFunc(a, b, c);

	return 0;
}