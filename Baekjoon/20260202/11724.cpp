#include <iostream>
#include <vector>

using namespace std;

int n, m, u, v;
vector<int> adj[1001];
bool visited[1001];
int cnt = 0;

void dfs(int vertex) {
    visited[vertex] = true;
    for (int next_vertex : adj[vertex]) {
        if (!visited[next_vertex]) dfs(next_vertex);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) { // range is important!
        if(!visited[i]) {
             dfs(i);
             cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
