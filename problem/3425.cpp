#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

stack<long> st;
vector<string> cmd;

void gostack(int val) {
	string str;
	long temp, temp2;
	st.push(val);
	if (abs(st.top()) >= 1000000000) {
		cout << "ERROR" << endl;
		return;
	}
	for (int i = 0; i < cmd.size(); ++i) {
		str = cmd[i];
		if (str.substr(0, 3) == "NUM") {
			temp = stol(str.substr(4));
			st.push(temp);
			if (abs(st.top()) >= 1000000000) {
				cout << "ERROR" << endl;
				return;
			}
		}
		else if (str == "POP") {
			if (st.empty()) {
				cout << "ERROR" << endl;
				return;
			}
			st.pop();
		}
		else if (str == "INV") {
			if (st.empty()) {
				cout << "ERROR" << endl;
				return;
			}
			temp = st.top();
			st.pop();
			temp = (-1) * temp;
			st.push(temp);
		}
		else if (str == "DUP") {
			if (st.empty()) {
				cout << "ERROR" << endl;
				return;
			}
			temp = st.top();
			st.push(temp);
		}
		else if (str == "SWP") {
			if (st.size() < 2) {
				cout << "ERROR" << endl;
				return;
			}
			temp = st.top();
			st.pop();
			temp2 = st.top();
			st.pop();
			st.push(temp);
			st.push(temp2);
		}
		else if (str == "ADD") {
			if (st.size() < 2) {
				cout << "ERROR" << endl;
				return;
			}
			temp = st.top();
			st.pop();
			temp += st.top();
			st.pop();
			st.push(temp);
			if (abs(st.top()) >= 1000000000) {
				cout << "ERROR" << endl;
				return;
			}
		}
		else if (str == "SUB") {
			if (st.size() < 2) {
				cout << "ERROR" << endl;
				return;
			}
			temp = st.top();
			st.pop();
			temp2 = st.top();
			st.pop();
			st.push(temp2 - temp);
			if (abs(st.top()) >= 1000000000) {
				cout << "ERROR" << endl;
				return;
			}
		}
		else if (str == "MUL") {
			if (st.size() < 2) {
				cout << "ERROR" << endl;
				return;
			}
			temp = st.top();
			st.pop();
			temp *= st.top();
			st.pop();
			st.push(temp);
			if (abs(st.top()) >= 1000000000) {
				cout << "ERROR" << endl;
				return;
			}
		}
		else if (str == "DIV") {
			if (st.size() < 2) {
				cout << "ERROR" << endl;
				return;
			}
			temp = st.top();
			st.pop();
			temp2 = st.top();
			st.pop();
			if (temp == 0) {
				cout << "ERROR" << endl;
				return;
			}
			if (temp * temp2 < 0) {
				st.push(abs(temp2) / abs(temp) * (-1));
			}
			else {
				st.push(abs(temp2) / abs(temp));
			}
		}
		else if (str == "MOD") {
			if (st.size() < 2) {
				cout << "ERROR" << endl;
				return;
			}
			temp = st.top();
			st.pop();
			temp2 = st.top();
			st.pop();
			if (temp == 0) {
				cout << "ERROR" << endl;
				return;
			}
			if (temp2 < 0) {
				st.push(abs(temp2) % abs(temp)* (-1));
			}
			else {
				st.push(abs(temp2) % abs(temp));
			}
		}
	}
	//수행 끝나고 stack 출력
	if (st.size() == 1) {
		cout << st.top() << endl;
		st.pop();
	}
	else {
		cout << "ERROR" << endl;
		while (!st.empty()) {
			st.pop();
		}
	}
}

int main() {
	string str;
	int num, value;

	while (1) {
		getline(cin, str);
		if (str == "QUIT") {
			break;
		}
		else if (str == "END") {
			//숫자입력받고
			cin >> num;
			for (int i = 0; i < num; ++i) {
				cin >> value;
				//명령어 실행
				gostack(value);
				while (!st.empty()) {
					st.pop();
				}
			}
			cout << endl;
			cmd.clear();
		}
		else {
			//명령어 입력
			cmd.push_back(str);
		}
	}

	return 0;
}