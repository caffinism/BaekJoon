#include <iostream>

using namespace std;

int n, cnt;
int check[15];

void dfs(int v) {
	int flag;
	if (v == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; ++i) {
		flag = 1;
		for (int j = 0; j < v; ++j) {
			//i���� ���� �ִ��� üũ
			//�Ǵ� �밢���� ���� �ִ��� üũ
			if (check[j] == i || abs(v - j) == abs(i - check[j])) {
				flag = 0;
				break;
			}
		}
		//flag�� 0�̸� i���� �� ���� ����
		if (flag == 1) {
			check[v] = i;
			dfs(v + 1);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	dfs(0);

	cout << cnt;

	return 0;
}