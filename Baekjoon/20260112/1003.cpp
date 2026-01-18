#include <iostream>

using namespace std;

int dp[50];

int fibonacci(int n) {
    if (n < 2) {
        return n;
    } 
    else if (dp[n]) {
        return dp[n];
    } 
    else {
        return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == 0) {
            cout << "1 0" << '\n';
        }
        else {
            cout << fibonacci(tmp - 1) << " " << fibonacci(tmp) << '\n';
        }
    }
    return 0;
}