#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
int n, m, Min = 100000;
int check[15];
vector<pii> house;
vector<pii> chicken;


void dfs(int v, int idx) {
	if (v == m) {
		int sum = 0;

		//집마다 치킨거리 계산
		for (int i = 0; i < house.size(); ++i) {
			int dist;
			dist = 1000000;
			for (int j = 0; j < chicken.size(); ++j) {
				if (check[j] == 1 && dist > (abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second))) {
					dist = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
				}
			}
			sum += dist;
		}

		if (sum < Min) {
			Min = sum;
			return;
		}
	}
	for (int i = idx; i < chicken.size(); ++i) {
		if (check[i] == 0) {
			check[i] = 1;
			dfs(v + 1, i + 1);
			check[i] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (temp == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	dfs(0, 0);

	cout << Min;

	return 0;
}