#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, k;

int tonum(char arr[]) {
	int res = 0;
	for (int i = 0; arr[i]; ++i) {
		res *= 10;
		res += arr[i] - '0';
	}
	return res;
}

int conv(int num, int l, int r) {
	//l,rüũ
	char buf[16];
	sprintf(buf, "%d", num);
	//���ڸ� 0�ƴ��� üũ
	if (buf[r] == '0' && l == 0) {
		return -1;
	}
	char temp;
	temp = buf[l];
	buf[l] = buf[r];
	buf[r] = temp;
	return tonum(buf);
}

int main() {
	int size = 0, temp, Max=0;

	cin >> n >> k;

	if (n == 1000000) {
		cout << n;
		return 0;
	}
	if (n < 10) {
		cout << -1;
		return 0;
	}
	if (n < 100 && n % 10 == 0) {
		cout << -1;
		return 0;
	}

	temp = n;
	while (temp > 0) {
		temp /= 10;
		size++;
	}

	queue<int> q;
	q.push(n);
	set<int> s;
	set<int>::iterator iter;
	
	//k�� ��ȯ
	for (int i = 0; i < k; ++i) {
		int sz = q.size();
		for (int j = 0; j < sz; ++j) {
			int num = q.front();
			q.pop();
			//��ȯ
			//��ȯ�� �տ� 0 ���� �ȵ�
			for (int I = 0; I < size; ++I) {
				for (int J = I + 1; J < size; ++J) {
					temp = conv(num, I, J);
					if (temp == -1) continue;
					s.insert(temp);
				}
			}
			//��ȯ����� push �ߺ� ���� ->�迭 �Ǵ� map ���
		}
		for (iter = s.begin(); iter != s.end(); ++iter) {
			q.push(*iter);
		}
		s.clear();
	}
	//k�� ���ȱ⶧���� q�� ���� ������ k�� ��ȯ�� ���ڵ�

	while (!q.empty()) {
		if (q.front() > Max) {
			Max = q.front();
		}
		q.pop();
	}

	cout << Max;

	return 0;
}
