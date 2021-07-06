#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int map[9][9];
bool row[9][9] = { false, };
bool col[9][9] = { false, };
bool box[3][3][9] = { false, };
vector<pii> vec;

void dfs(int v) {
	if (v == vec.size()) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << map[i][j] << ' ';
			}cout << endl;
		}
		exit(0);
	}
	for (int i = 1; i <= 9; ++i) {
		int x = vec[v].first;
		int y = vec[v].second;
		//숫자 중복확인
		if (row[x][i] == false && col[y][i] == false && box[x / 3][y / 3][i] == false) {
			//중복아니다?
			box[x / 3][y / 3][i] = col[y][i] = row[x][i] = true;
			map[x][y] = i;
			dfs(v + 1);
			map[x][y] = 0;
			box[x / 3][y / 3][i] = col[y][i] = row[x][i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				vec.push_back(make_pair(i, j));
			}
			else {
				row[i][map[i][j]] = true;
				col[j][map[i][j]] = true;
				box[i / 3][j / 3][map[i][j]] = true;
			}
		}
	}
	dfs(0);
	return 0;
}