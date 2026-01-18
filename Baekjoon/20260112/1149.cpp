#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
 
int dp[1001][1001];
int arr[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
 
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
 
    for (int i = 1; i < n; i++){
        dp[i][0]=min(dp[i-1][1] + arr[i][0],dp[i-1][2] + arr[i][0]);
        dp[i][1]=min(dp[i-1][0] + arr[i][1],dp[i-1][2] + arr[i][1]);
        dp[i][2]=min(dp[i-1][0] + arr[i][2],dp[i-1][1] + arr[i][2]);
    }

    int ans = INT_MAX;

    for (int i = 0; i<3; i++){
        ans = min(ans,dp[n-1][i]);
    }
    cout << ans << '\n';
    return 0;
}