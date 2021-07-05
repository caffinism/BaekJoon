#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int l, c;
vector<bool> check;
vector<char> str, res;

void dfs(int d) {
	if (d == l) {
		int m, j;
		m = j = 0;
		for (int i = 0; i < l; ++i) {
			if (res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u') {
				m++;
			}
			else j++;
		}
		if (m >= 1 && j >= 2) {
			for (int i = 0; i < l; ++i) cout << res[i];
			cout << '\n';
		}
	}
	else {
		for (int i = 0; i < c; ++i) {
			if (d == 0) {
				check[i] = true;
				res[d] = str[i];
				dfs(d + 1);
				check[i] = false;
			}
			else if (res[d-1] < str[i] && check[i] == false) {
				check[i] = true;
				res[d] = str[i];
				dfs(d + 1);
				check[i] = false;
			}
		}
	}
}

int main() {

	cin >> l >> c;

	check.resize(c);
	str.resize(c);
	res.resize(l);

	for (int i = 0; i < c; ++i) {
		cin >> str[i];
		check[i] = false;
	}
	sort(str.begin(), str.end());

	dfs(0);


	return 0;
}