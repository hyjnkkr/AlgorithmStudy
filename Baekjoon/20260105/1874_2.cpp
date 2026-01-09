#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// int arr[100001];
stack<int> a; // a stack to save the opeartor
vector<int> v; // a vector array to save user input
vector<char> oper; // save the operator +/-. it'll be used for final result print.

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;

	// save the user input to v
	for (int i = 0; i < n; i++) {
	    int tmp; cin >> tmp;
		v.push_back(tmp);
	}

	int num = 1; // iteration starts from 1 -> n
	int start = 0; // the current element in v

	// if the while loop breaks before emptying the stack,
	// print NO

	while (1) {
	    //
	    if (start >= n) break;

		// only runs in very first iteration (num == 1)
		if (a.empty()) {
		    a.push(num);
			oper.push_back('+');
			num++;
		} else {
		    // e.g. a.top() == 5, v[start] (current) == 3
			// impossible: we have to pop 4, 5 first.
		    if (a.top() > v[start]) break;
			if (a.top() == v[start]) {
			    a.pop();
				oper.push_back('-');
				start++;
			} else {
			    a.push(num);
				oper.push_back('+');
				num++;
			}
		}
	}

	if(!a.empty()) cout << "NO";
	else {
	    for (int i = 0; i < oper.size(); i++) {
			cout << oper[i] << '\n';
		}
	}

	return 0;
}
