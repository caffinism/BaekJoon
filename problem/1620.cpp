#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef pair<int, string> pis;
typedef pair<string, int> psi;

int main() {
	int n, m;
	string name;
	map<int, string> mp;
	map<string, int> mpp;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> name;
		mp.insert(pis(i + 1, name));
		mpp.insert(psi(name, i + 1));
	}

	for (int i = 0; i < m; ++i) {
		cin >> name;
		n = atoi(name.c_str());
		if (n==0) {
			cout << mpp[name] << '\n';
		}
		else {
			cout << mp[n] << '\n';
		}
	}

	return 0;
}