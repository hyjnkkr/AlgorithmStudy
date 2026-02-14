#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n, m;
int mvx[4] = {0, 1, 0, -1};
int mvy[4] = {1, 0, -1, 0};
int grid[101][101];
bool visited[101][101];

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + mvx[i];
            int ny = cur.second + mvy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (grid[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    grid[nx][ny] = grid[cur.first][cur.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            grid[i][j] = row[j] - '0';
        }
    }

    bfs();

    cout << grid[n - 1][m - 1] << '\n';

    return 0;
}