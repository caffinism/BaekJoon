#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> graph[100001];
int depth[100001];
int ancient[100001][20]; //[x][y] x�� 2^y ��° ����

void makeTree(int cur, int parent) {
	depth[cur] = depth[parent] + 1;
	ancient[cur][0] = parent; //cur�� 2^0 ��° ���� �� �θ�

	for (int i = 1; i < 20; ++i) {
		int tmp = ancient[cur][i - 1];
		ancient[cur][i] = ancient[tmp][i - 1];
	}

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (next != parent) {
			makeTree(next, cur);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	depth[0] = -1;
	makeTree(1, 0); // 1���� ��Ʈ�� �ϴ� Ʈ�� ����

	cin >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		//a depth�� �� ũ�� �ٲ�
		if (depth[a] < depth[b]) {
			int temp = a;
			a = b;
			b = temp;
		}

		//a ������ ���󰡼� depth�� ����
		for (int i = 19; i >= 0; --i) {
			if (depth[b] <= depth[ancient[a][i]]) {
				a = ancient[a][i];
			}
		}

		// depth�� ������ a!=b�� ��� ���� ���� ����
		int ans = a;
		if (a != b) {
			for (int i = 19; i >= 0; --i) {
				if (ancient[a][i] != ancient[b][i]) {
					a = ancient[a][i];
					b = ancient[b][i];
				}
				ans = ancient[a][i];
			}
		}

		cout << ans <<'\n';
	}

	return 0;
}