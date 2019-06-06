#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
	Bracket(char type, int position) :
		type(type),
		position(position)
	{}

	bool Matchc(char c) {
		if (type == '[' && c == ']')
			return true;
		if (type == '{' && c == '}')
			return true;
		if (type == '(' && c == ')')
			return true;
		return false;
	}

	char type;
	int position;
};

int main() {
	string text;
	getline(cin, text);

	stack <Bracket> opening_brackets_stack;
	int Result = -1; 

	for (int position = 0; position < text.length(); ++position) {
		char next = text[position];

		if (next == '(' || next == '[' || next == '{') {
			opening_brackets_stack.push(Bracket(next, position+1));
		}

		if (next == ')' || next == ']' || next == '}') {
			if (opening_brackets_stack.empty()) {
				Result = position + 1; 
				break; 
			}
			else {
				Bracket top = opening_brackets_stack.top();
				opening_brackets_stack.pop();
				if (!top.Matchc(next)) {
					Result = position + 1; 
					break; 
				}
			}
		}
	}
	if (Result != -1) {
		cout << Result << endl;	
	}
	else if (!opening_brackets_stack.empty()) {
		cout << opening_brackets_stack.top().position << endl;
	}
	else {
		cout << "Success" << endl;
	}
	return 0;
}
