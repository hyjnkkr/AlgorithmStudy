#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> s; // 1 2 3 4 5 6 7 8
vector<char> res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    // 4 3 6 8 7 5 2 1
    int cur = 1;
    for (int i = 0; i < n; i++) {
        int input; cin >> input;
        while (cur <= input) {
            s.push(cur);
            res.push_back('+');
            cur++;
        }

        // 4 == 4
        if (s.top() == input) {
            s.pop();
            res.push_back('-');
        } else {
            cout << "NO" << '\n';
            return 0;
        }
        
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << '\n';
    }

    return 0;
}