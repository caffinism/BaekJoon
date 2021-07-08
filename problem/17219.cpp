#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef pair<string, string> pss;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	string url, pwd;
	map<string, string> mp;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> url >> pwd;
		mp.insert(pss(url, pwd));
	}
	for (int i = 0; i < m; ++i) {
		cin >> url;
		cout << mp[url] << '\n';
	}
	return 0;
}