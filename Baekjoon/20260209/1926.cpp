#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int paper[501][501];
bool visited[501][501];

int mvx[4] = {0, 1, 0, -1};
int mvy[4] = {1, 0, -1, 0};

int bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    int area = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        area++;

        for (int i = 0; i < 4; ++i) {
            int nx = curr.first + mvx[i];
            int ny = curr.second + mvy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && paper[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return area;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> paper[i][j];
        }
    }

    int num_of_paintings = 0;
    int max_area = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (paper[i][j] == 1 && !visited[i][j]) {
                num_of_paintings++;
                max_area = max(max_area, bfs(i, j));
            }
        }
    }

    cout << num_of_paintings << '\n' << max_area << '\n';

    return 0;
}