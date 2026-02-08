#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> v;

dfs() {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> c;

    for (int i = 0; i < c; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());   

    dfs(r);

    for (int i = 1; i <= n; i++) {
        cout << visited_order[i] << '\n';
    }

    return 0;
}
