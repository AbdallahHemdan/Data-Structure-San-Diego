#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <stack>

using namespace std; 

class StackWithMax {
	stack<int> St;

public:
	
	void Push(int value) {
		if (St.empty()) {
			St.push(value);
		}
		else {
			if (value > St.top()) {
				St.push(value);
			}
			else {
				St.push(St.top());
			}
		}
	}

	void Pop() {
		St.pop();
	}

	int Max() const {
		return St.top();
	}
};

int main() {
	int num_queries = 0;
	cin >> num_queries;

	string query;
	string value;

	StackWithMax St;

	for (int i = 0; i < num_queries; ++i) {
		cin >> query;
		if (query == "push") {
			cin >> value;
			St.Push(std::stoi(value));
		}
		else if (query == "pop") {
			St.Pop();
		}
		else if (query == "max") {
			cout << St.Max() << "\n";
		}
		else {
			assert(0);
		}
	}
	return 0;
}
