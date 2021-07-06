#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, Max;
vector<string> str;
vector<char> alpha;
int arr[26];
bool check[10] = { false, };
int str2num() {
	int sum = 0, temp;
	for (int i = 0; i < str.size(); ++i) {
		temp = 0;
		for (int j = 0; j < str[i].length(); ++j) {
			temp *= 10;
			temp += arr[str[i][j] - 'A'];
		}
		sum += temp;
	}
	return sum;
}

void dfs(int v) {
	if (v == alpha.size()) {
		int val = str2num();
		if (Max < val) {
			Max = val;
		}
		return;
	}
	for (int i = 0; i <= 9; ++i) {
		if (check[i] == false) {
			check[i] = true;
			arr[alpha[v] - 'A'] = i;
			dfs(v + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string temp;
		cin >> temp;
		str.push_back(temp);
		for (int i = 0; i < temp.length(); ++i) {
			arr[temp[i] - 'A'] = 1;
		}
	}
	for (int i = 0; i < 26; ++i) {
		if (arr[i] == 1) {
			alpha.push_back('A' + i);
		}
	}
	dfs(0);
	cout << Max;
	return 0;
}