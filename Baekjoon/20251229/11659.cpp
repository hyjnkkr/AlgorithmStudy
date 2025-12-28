#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, i, j;
	cin >> n >> m;
	int arr[100001];
	int dp[100001];

	// get arr (2nd line)
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = dp[i - 1] + arr[i];
	}

	for (i = 0; i < m; i++) {
		int sum = 0;
		int n1, n2;
		cin >> n1 >> n2;
		cout << dp[n2] - dp[n1 - 1] << "\n";
	}
	return 0;
}