#include <iostream>
using namespace std;

int tree[26][2];

void preorder(int v) {
	cout << (char)(v+'A');
	if (tree[v][0] != -1) preorder(tree[v][0]);
	if (tree[v][1] != -1) preorder(tree[v][1]);
}

void inorder(int v) {
	if (tree[v][0] != -1) inorder(tree[v][0]);
	cout << (char)(v+'A');
	if (tree[v][1] != -1) inorder(tree[v][1]);
}

void postorder(int v) {
	if (tree[v][0] != -1) postorder(tree[v][0]);
	if (tree[v][1] != -1) postorder(tree[v][1]);
	cout << (char)(v+'A');
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		char root, left, right;
		cin >> root >> left >> right;
		tree[root - 'A'][0] = (left=='.') ? (-1) : (left - 'A');
		tree[root - 'A'][1] = (right=='.') ? (-1) : (right - 'A');
	}

	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	cout << endl;

	return 0;
}