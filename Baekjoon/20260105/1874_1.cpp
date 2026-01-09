// 현진
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> a; // a stack to save the opeartor
vector<char> oper; // save the operator +/-. it'll be used for final result print.

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int cnt = 1; // iteration starts from 1 -> n

	// get n amount of user input
	for (int i = 0; i < n; i++) {
	    int num; cin >> num; // user input

		// push the number into the stack until cnt (iteration) reaches num (user input)
		while (cnt <= num) {
		    a.push(cnt++);
			oper.push_back('+');
		}

		// 'pop' the item
		// if a 'larger' number is on the top of the stack, the desired element canot be popped,
		// so print NO and return
		if (a.top() == num) {
		    a.pop();
			oper.push_back('-');
		} else {
		    cout << "NO";
			return 0;
		}
	}

    for (int i = 0; i < oper.size(); i++) {
		cout << oper[i] << '\n';
    }
	return 0;
}
