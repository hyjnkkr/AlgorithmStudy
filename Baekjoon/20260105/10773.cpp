#include <iostream>
#include <stack>

using namespace std;

stack<long long> s;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            s.pop();
        } else {
            s.push(tmp);
        }
    }

    int sum = 0;
    while (s.size() != 0) {
        sum += s.top();
        s.pop();
    }
    cout << sum;
}
