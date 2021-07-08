#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n, m;
int arr[10002];
vector<int> vec;
deque<int> dq, tmp;

void dfs(int v, int idx) {
	if (v == m) {
		while (!dq.empty()) {
			cout << dq.front() << ' ';
			tmp.push_back(dq.front());
			dq.pop_front();
		}cout << '\n';
		while (!tmp.empty()) {
			dq.push_back(tmp.front());
			tmp.pop_front();
		}
	}
	else {
		for (int i = 0; i < n; ++i) {
			if (arr[vec[i]] == 0) {
				arr[vec[i]]=1;
				dq.push_back(vec[i]);
				dfs(v + 1, i);
				dq.pop_back();
				arr[vec[i]]=0;
			}
		}
	}
}

int main() {
	int val;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> val;
		vec.push_back(val);
	}
	sort(vec.begin(), vec.end());

	dfs(0, 0);
	return 0;
}