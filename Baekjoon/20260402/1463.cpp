#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int dp[1000001];

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i-1]+1;
        // if i can be divided by 3
        if (i % 3 == 0) {
            dp[i] = min(dp[i/3]+1, dp[i]);
        // if i can be divided by 2
        } 
        if (i % 2 == 0) {
            dp[i] = min(dp[i/2]+1, dp[i]);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}