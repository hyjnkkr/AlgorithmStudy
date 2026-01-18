#include <iostream>

using namespace std;

int dp[1001][10];
int N;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> N;
    
    for (int i = 0; i<=9; i++){
        dp[1][i] = 1;
    }

    for (int i=2; i<=N; i++){
        for(int j = 0; j<=9; j++){
            for(int k = 0; k<=j; k++){
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= 10007;
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i<=9; i++){
        ans += dp[N][i];
        ans = ans % 10007;
    }
    
    cout << ans << '\n';
    return 0;
}
