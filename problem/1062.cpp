#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool arr[26] = {false, };
vector<string> str;
int n, k, Max = 0;

void dfs(int v, int c) {
	if (v == k) {
		int cnt = 0;

		for (int i = 0; i < str.size(); ++i) {
			int flag;
			flag = 0;
			for (int j = 0; j<str[i].length(); ++j) {
				if (arr[str[i][j] - 'a'] == false) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				cnt++;
			}
		}

		if (cnt > Max) Max = cnt;
	}
	else {
		for (int i = c; i < 26; ++i) {
			if (arr[i] == false) {
				arr[i] = true;
				dfs(v + 1, i);
				arr[i] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;


	for (int i = 0; i < n; ++i) {
		string temp;
		int cnt;
		cin >> temp;
		cnt = 0;
		for (int j = 0; j < 26; ++j) {
			if (temp.find('a' + j) != string::npos) {
				cnt++;
			}
		}
		if (cnt <= k) {
			str.push_back(temp.substr(4, temp.length() - 8));
		}
	}

	if (k < 5) {
		cout << 0 << endl;
		return 0;
	}
	if (k == 26) {
		cout << n << endl;
		return 0;
	}


	arr['a' - 'a'] = true;
	arr['n' - 'a'] = true;
	arr['t' - 'a'] = true;
	arr['i' - 'a'] = true;
	arr['c' - 'a'] = true;
	dfs(5, 0);

	cout << Max;

	return 0;
}