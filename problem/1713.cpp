#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
	int n, t;
	vector<tuple<int, int, int>> table;
	vector<int> res;

	cin >> n >> t;

	for (int i = 0; i < t; ++i) {
		int reco, flag;

		cin >> reco;

		flag = 0;
		for (int i = 0; i < table.size(); ++i) {
			if (reco == get<2>(table[i])) {
				get<0>(table[i]) += 1;
				flag = 1;
				break;
			}
		}

		if (flag == 0) {
			if (table.size() < n) {
				table.push_back(make_tuple(1, i, reco));
			}
			else if (table.size() == n) {
				sort(table.begin(), table.end(), less<>());
				table[0] = make_tuple(1, i, reco);
			}
			else { cout << "ERROR"; }
		}
	}

	for (int i = 0; i < table.size(); ++i) {
		res.push_back(get<2>(table[i]));
	}
	sort(res.begin(), res.end(), less<>());

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << ' ';
	}cout << endl;

	return 0;
}