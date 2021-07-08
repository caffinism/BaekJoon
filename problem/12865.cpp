#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int n, k, w, v;
int arr[101][100001] = { 0, };
vector<pii> vec;
int main() {
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> w >> v;
		vec.push_back(pii(w, v));
	}
	sort(vec.begin(), vec.end());

	for (int i = 1; i<=n; ++i){
		int weight = vec[i-1].first;
		int value = vec[i-1].second;
		for (int j = 0; j <= k; ++j) {
			if (j < weight) {
				arr[i][j] = arr[i - 1][j];
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - weight] + value);
			}
		}
	}

	cout << arr[n][k];

	return 0;
}