#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int r, c, cnt;
char map[51][51];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
queue<pii> ddg_q, water_q;
pii ddg;
vector<pii> water;
int water_vt[50][50] = { 0, }, ddg_vt[50][50] = { 0, };

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				ddg = make_pair(i, j);
			}
			if (map[i][j] == '*') {
				water.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < water.size(); ++i) {
		pii cur_water = water[i];
		water_q.push(cur_water);
		water_vt[cur_water.first][cur_water.second] = 1;
	}

	ddg_q.push(ddg);
	ddg_vt[ddg.first][ddg.second] = 1;

	while (!water_q.empty()) {
		pii cur_water = water_q.front();
		water_q.pop();
		for (int i = 0; i < 4; ++i) {
			int X, Y;
			X = cur_water.first + dx[i];
			Y = cur_water.second + dy[i];
			if (X >= 0 && X < r && Y >= 0 && Y < c) {
				if (map[X][Y] == '.' && water_vt[X][Y] == 0) {
					water_vt[X][Y] = water_vt[cur_water.first][cur_water.second] + 1;
					water_q.push(make_pair(X, Y));
				}
			}
		}
	}

	int flag = 0;
	while (!ddg_q.empty()) {
		pii cur_ddg = ddg_q.front();
		ddg_q.pop();
		for (int i = 0; i < 4; ++i) {
			int X, Y;
			X = cur_ddg.first + dx[i];
			Y = cur_ddg.second + dy[i];
			if (X >= 0 && X < r && Y >= 0 && Y < c) {
				if (map[X][Y] == 'D') {
					cout<< ddg_vt[cur_ddg.first][cur_ddg.second]<<endl;
					flag = 1;
					break;
				}
				if (ddg_vt[X][Y]==0 && map[X][Y] != 'X' && (water_vt[X][Y]==0||ddg_vt[cur_ddg.first][cur_ddg.second]+1 < water_vt[X][Y])) {
					ddg_vt[X][Y] = ddg_vt[cur_ddg.first][cur_ddg.second] + 1;
					ddg_q.push(make_pair(X, Y));
				}
			}
		}
		if (flag == 1) break;
	}

	if (flag == 0) cout << "KAKTUS" << endl;

	return 0;
}