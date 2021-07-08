#include <iostream>
using namespace std;

int main() {
	int n, temp, num2=0, num5=0;
	cin >> n;

	for (int i = n; i > 1; --i) {
		temp = i;
		while (temp % 2 == 0) {
			num2++;
			temp /= 2;
		}
		while (temp % 5 == 0) {
			num5++;
			temp /= 5;
		}
	}

	cout << min(num2, num5);

	return 0;
}